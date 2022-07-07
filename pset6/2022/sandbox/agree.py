'''
Logical Operators
'''
from cs50 import get_string

# prompt user to agree (yes or no)
usr_input = get_string("Do you agree (Y/N): ").lower()[0]

if usr_input == 'y':
    print("Agreed.")
elif usr_input == 'n':
    print("Disagreed.")