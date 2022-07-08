from cs50 import get_string
import csv

snacks = {
    "Chips": 0,
    "Chocolate": 0,
    "Fruit": 0,
    "Others": 0
}

with open("snacks.csv", "r") as file:
    reader = csv.reader(file)
    next(reader)
    for row in reader:
        person = row[0]     #row[0] is the Person
        snack = row[1]      #row[1] is the Snack
        try:
            snacks[snack] += 1
        except:
            snacks["Others"] += 1



for snack in snacks:
    print(f"{snack}:{snacks[snack]}")