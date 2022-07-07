from cs50 import get_int

def main():
    usr_input = get_int("How many times to meow: ")
    meow(usr_input)

def meow(n):
    for i in range(n):
        print("Meow.")

main()
