from cs50 import get_string
import csv

snacks = {
    "Chips": 0,
    "Chocolate": 0,
    "Fruit": 0,
    "Others": 0
}

with open("snacks.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        snack = row["Snack"]
        try:
            snacks[snack] += 1
        except:
            snacks["Others"] += 1



for snack in snacks:
    print(f"{snack}:{snacks[snack]}")