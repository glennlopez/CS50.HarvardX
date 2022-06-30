import cs50

# When importing and not "using" a specific lib
# programmer needs to add cs50.<library to use> example - cs50.get_int()

#x = cs50.get_int("x: ")
#y = cs50.get_int("y: ")

try:
    x = int(input("x: "))
except ValueError:
    print("value type error!")
    exit()

try:
    y = int(input("y: "))
except ValueError:
    print("value type error!")
    exit()

print(f"Sum of x and y: {x + y}");