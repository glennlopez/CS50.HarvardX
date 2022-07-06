'''
 determine if number is ever or odd
'''
from cs50 import get_int

# ask user for number
usr_int = get_int("Number: ")

if (usr_int % 2) == 0:
    # if even, print out even
    print(f"Number {usr_int} is even.")
elif(usr_int % 2) != 0:
    # if odd, print out odd
    print(f"Number {usr_int} is odd.")
else:
    print(f"Unexpected Input: {usr_int}")