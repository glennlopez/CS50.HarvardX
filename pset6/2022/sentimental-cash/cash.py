# libs to import
from cs50 import get_float

# get changed owed
change = -1
while change < 0:
    change = get_float("Change owed: ")

# calculate how many coins to dispense (Quarters: 25, Dimes: 10, Nickels: 5, and pennies: 1)
total_coins = 0
while change != 0.0:
    if change >= 0.25:
        change -= 0.25
        change = round(change, 2)
        total_coins += 1

    elif change >= 0.10:
        change -= 0.10
        change = round(change, 2)
        total_coins += 1

    elif change >= 0.05:
        change -= 0.05
        change = round(change, 2)
        total_coins += 1

    elif change >= 0.01:
        change -= 0.01
        change = round(change, 2)
        total_coins += 1
print(total_coins)
