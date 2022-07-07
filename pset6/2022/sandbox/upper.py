from cs50 import get_string

usr_str = get_string("Before: ")
print("After: ", end="")
for i in usr_str:
    print(i.upper(), end="")
print()

print(f"Lower cased: {usr_str.lower()}")