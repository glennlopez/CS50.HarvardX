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
        # itterate through the csv files row
        for row in reader:

            # create a team dictionary with key:value pair as team:rating
            team = {'team': row['team'], 'rating': int(row['rating'])}

            # append the team {key:value} dictionary to the teams[] list
            teams.append(team)


# display all the teams stored in teams[]
for i in range(len(teams)):
    print(teams[i])

#print(teams[0]) #debug