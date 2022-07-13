# import required libraries
import csv
import sys

# take a command line argument for which file to open
if len(sys.argv) != 2:
    sys.exit("Usage: python teams.py <FILENAME>")

teams = []
counts = {} #key: name of team, value: how many tournaments team has won

# open and read the file
with open(sys.argv[1], "r") as file:
    reader = csv.DictReader(file)
    # store the teams in the file in a list (teams = [])
    for row in reader:
        # set the key value pair in the team as per csv file
        team = {row['team']:row['rating']}
        # append the team to list of teams
        teams.append(team)


# display all the teams stored in teams[]
for i in range(len(teams)):
    print(teams[i])