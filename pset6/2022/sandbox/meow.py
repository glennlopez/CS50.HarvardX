from cs50 import get_int

def main():
    usr_input = get_int("How many times to meow: ")
    for i in range(usr_input):
        meow()

def meow():
    print("Meow.")

main()
