from cs50 import get_int

def meow():
    print("Meow.")

usr_input = get_int("How many times to meow: ")
for i in range(usr_input):
    meow()
