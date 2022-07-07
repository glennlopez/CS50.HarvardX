'''
Dictionary example: Key Value Pair
'''
#from cs50 import get_str

people = {
    # Name:ID
    "Glenn":"12345",
    "Greg":"5453",
    "Lopez":"12345",
    "Amber":"87632",
    "Stacy":"4765756"
}


# Print the ID of a specific Name
for name in people:
    if "Glenn" in name:
        print(f"Found! - ID: {people[name]}")

# Print the name with the specific ID
find = [k for k, name in people.items() if name == '12345']
print(find)