from flask import Flask

app = Flask(__name__)


@app.route("/")
def index():
    return "<h3>Functional test</h3>"