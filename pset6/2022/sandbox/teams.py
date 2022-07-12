# import required libraries
import csv
import sys

# take a command line argument for which file to open
if len(sys.argv) != 2:
    sys.exit("Usage: python teams.py <FILENAME>")

teams = []
# open and read the file
with open(sys.argv[1], "r") as file:
    reader = csv.DictReader(file)
    # store the teams in the file in a list (teams = [])
    for row in reader:
        team = row['team']
        teams.append(team)


# display all the teams stored in teams[]
for i in range(len(teams)):
    print(teams[i])