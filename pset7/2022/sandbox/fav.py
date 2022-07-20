import csv
from cs50 import SQL

db = SQL("sqlite:///fav.db") # creates an SQL database on disk

title = input("Title: ").strip()

# use python to talk to the database
rows = db.execute("SELECT COUNT(*) AS counter FROM fav WHERE title LIKE ?", title)

row = rows['counter']