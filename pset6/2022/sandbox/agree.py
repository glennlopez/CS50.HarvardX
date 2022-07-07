'''
Logical Operators
'''
from cs50 import get_string

# prompt user to agree (yes or no)
usr_input = get_string("Do you agree (Y/N): ")

if usr_input.lower()[0] == 'y':
    print("Agreed.")
elif usr_input.lower()[0] == 'n':
    print("Disagreed.")