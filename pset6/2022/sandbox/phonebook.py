'''
Dictionary example: Key Value Pair
'''
from cs50 import get_string

people = {
    # Name:ID
    "Glenn":"12345",
    "Greg":"5453",
    "Lopez":"12345",
    "Amber":"87632",
    "Stacy":"4765756"
}

# ask user for a name they would like to look up
find = get_string("Look up: ")
result = (f"User {find}, not found.")

# Print the ID of a specific Name
for name in people:
    if find in name:
        result = (f"Found {find} with ID: {people[name]}")

print(result)
