# TODO
from cs50 import get_int

def main():
    # length
    for x in range(get_height()):
        print("#", end="")
    print("")


# prompt the user for Height
def get_height():
    while True:
        height = get_int("Height: ")
        if height >= 0:
            return height

main()
