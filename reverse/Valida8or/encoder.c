#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


unsigned char key[] = {0xDE, 0xAD, 0xBE, 0xEF};
char key2 = 0x3F;

void encode(unsigned char data[], size_t length) {
	for (size_t i = 0; i < length; i += 4) {
		data[i] ^= key[0];
		data[i + 1] ^= key[1];
		data[i + 2] ^= key[2];
		data[i + 3] ^= key[3];
		for (size_t j = i; j < i + 4; j += 1) {
			data[j] ^= (key2++);
		}
	}
}

int main() {
	unsigned char flag[100];
	printf("[?] Give me flag to check:\n");
	scanf("%s", &flag);
	size_t length = strlen(flag);
	encode(flag, length);
	printf("%s\n{", flag);
	for (size_t i = 0; i < length; i++) {
		printf("0x%x, ", flag[i]);
	}
	printf("}\n");
	return 0;
}