from flask import Flask, render_template, request

app = Flask(__name__)

#index.html logic
@app.route("/", methods=["POST", "GET"])
def index():
    if request.method == "GET":
        return render_template("index.html")

    elif request.method == "POST":
        return render_template("greet.html",  name = request.form.get("fname", "world"))
