'''
Dictionaries using CSV files
'''
from cs50 import get_string
import csv

# open a file using open(file,a/r/w)
csv_file = open("phonebook.csv", "a")

# ask user for Name
name = get_string("Name: ")

# ask user for Number
num = get_string("Number: ")

# write the name and number to the newly opened csv file
writer = csv.writer(csv_file)
writer.writerow([name, num])

# close the file
csv_file.close()