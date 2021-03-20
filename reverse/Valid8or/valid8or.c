#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

unsigned char key[] = {0xDE, 0xAD, 0xBE, 0xEF};
char key2 = 0x3F;
char pwd[] = {0x87, 0x81, 0x9e, 0xca, 0xe6, 0x9e, 0xcf, 0x9c, 0xc6, 0xd4, 0xc0, 0xfa, 0xfd, 0xd5, 0x81, 0xc5, 0xbd, 0xa2, 0x87, 0xc8, 0xe5, 0xc6, 0x96};

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
	if (strncmp(flag, pwd, length) == 0) {
		printf("[*] Flag is correct, go and submit it!\n");
	}
	else {
		printf("[!] Flag is incorrect, try harder!\n");
	}
	return 0;
}