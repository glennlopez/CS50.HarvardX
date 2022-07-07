'''
Search through a list of names for a
specific name
'''

from cs50 import get_string
import sys

# List of names
names = ['George', 'Abe', 'Gabe', 'Alex', 'Greg', 'Glenn', 'Austin', 'Mark', 'Dave', 'Frank']

# Ask user to what name to look for in the list
usr = get_string("Name to look for: ")

# Confirm if the name is in the list of names
if usr in names:
    print(f"{usr} name was found!")
    sys.exit(0)
else:
    print(f"{usr}, was not found in the list.")
    sys.exit(1)