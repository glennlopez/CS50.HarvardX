from cs50 import get_int

# main
def main():
    usr_input = get_height()
    draw(usr_input)


# prompt the user for Height
def get_height():
    while True:
        height = get_int("Height: ")
        if height >= 0:
            return height

# draw the bricks
def draw(usr_input):
    width = usr_input
    for y in range(usr_input):
        for x in range(width):
            print("#", end="")
        print("")
        width -= 1

# excecute main if main exists as a def module
if __name__ == '__main__':
    main()
