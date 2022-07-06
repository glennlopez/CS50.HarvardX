import random

my_point = 5
thier_point = random.randint(1, 10)


# my point is larger
if my_point > thier_point:
    print(f"my_point ({my_point}) is larger thier thier_point")

# thier point is larger
elif thier_point > my_point:
    print(f"thier point ({thier_point}) is larger than my_point")

# mypoint and thier point is equal
else:
    print(f"my_point ({my_point}) is the same as thier_point ({thier_point})")

