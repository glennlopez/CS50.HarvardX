from cs50 import get_int
import sys

#numbers in the list
numbers = [80, 53, 13, 12, 6, 0, 1, 367]

#ask user to find a specific number
find = get_int("Find the number: ")

if find in numbers:
    print(f"Number {find} was found!")
    sys.exit(0)
else:
    print(f"Number {find}, doesnt exist.")
    sys.exit(1)
