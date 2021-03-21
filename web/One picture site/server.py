from flask import Flask, render_template, request, redirect, url_for, flash, make_response
from random import choice
import base64

app = Flask(__name__, static_url_path='/static')
DEFAULT = 'picture.jpg'
ALPH = [chr(c) for c in range(ord('a'), ord('z') + 1)] + [chr(c) for c in range(ord('A'), ord('Z') + 1)] + [chr(c) for c in range(0, 10)]
FLAG = 'flag.png'


def is_admin(value) -> bool:
    try:
        return base64.b64decode(request.cookies.get('session')) == b'admin=True'
    except Exception as e:
        return False


def random_key() -> str:
    data = []
    for i in range(12):
        data.append(choice(ALPH))
    return ''.join(data)


app.config['SECRET_KEY'] = random_key()


@app.route('/', methods=['GET'])
def main():
    resp = None
    if request.cookies.get('session') and is_admin(request.cookies.get('session')):
        resp = make_response(render_template('index.html', data=FLAG))
    else:
        resp = make_response(render_template('index.html', data=DEFAULT))
        resp.set_cookie('session', base64.b64encode(b'admin=False'))
    return resp


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=25001)
