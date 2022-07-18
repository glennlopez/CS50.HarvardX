import csv
import sys

AGATC = 0
TTTTTTCT = 0
AATG = 0
TCTAG = 0
GATA = 0
TATC = 0
GAAA = 0
TCTG = 0

def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py <database> <sequence>")
        exit(1)

    # get the database and sequence filenames
    database = sys.argv[1]
    sequence = sys.argv[2]

    # TODO: Read database file into a variable
    dna_db = []

    # append to db for small database
    if database.find('small') > 0:
        with open(database) as db_file:
            reader = csv.DictReader(db_file)
            for row in reader:
                dna = {'name':row['name'], 'AGATC':int(row['AGATC']), 'AATG':int(row['AATG']), 'TATC':int(row['TATC'])}
                dna_db.append(dna)

    # append to db for large database
    if database.find('large') > 0:
        with open(database) as db_file:
            reader = csv.DictReader(db_file)
            for row in reader:
                dna = {
                'name':row['name'],
                'AGATC':int(row['AGATC']),
                'TTTTTTCT':int(row['TTTTTTCT']),
                'AATG':int(row['AATG']),
                'TCTAG':int(row['TCTAG']),
                'GATA':int(row['GATA']),
                'TATC':int(row['TATC']),
                'GAAA':int(row['GAAA']),
                'TCTG':int(row['TCTG'])
                }
                dna_db.append(dna)

    # TODO: Read DNA sequence file into a variable
    sq_file = open(sequence, 'r')
    sequence_file = sq_file.read()

    # TODO: Find longest match of each STR in DNA sequence
    global AGATC, TTTTTTCT, AATG, TCTAG, GATA, TATC, GAAA, TCTG
    AGATC = longest_match(sequence_file, 'AGATC')
    TTTTTTCT = longest_match(sequence_file, 'TTTTTTCT') # Large
    AATG = longest_match(sequence_file, 'AATG')
    TCTAG = longest_match(sequence_file, 'TCTAG') # Large
    GATA = longest_match(sequence_file, 'GATA') # Large
    TATC = longest_match(sequence_file, 'TATC')
    GAAA = longest_match(sequence_file, 'GAAA') # Large
    TCTG = longest_match(sequence_file, 'TCTG') # Large

    #debug
    print(f"AGATC {AGATC}")
    print(f"TTTTTTCT {TTTTTTCT}")
    print(f"AATG {AATG}")
    print(f"TCTAG {TCTAG}")
    print(f"GATA {GATA}")
    print(f"TATC {TATC}")
    print(f"GAAA {GAAA}")
    print(f"TCTG {TCTG}")
    print()

    # TODO: Check database for matching profiles
    # for small database
    if database.find('small') > 0:
        for dna in dna_db:
            if dna['AGATC'] == AGATC and dna['AATG'] == AATG and dna['TATC'] == TATC:
                print(dna['name'])

    # for large database
    if database.find('large') > 0:
        print(find_match(dna_db))
        '''
        for dna in dna_db:
            if dna['AGATC'] == AGATC and dna['TTTTTTCT'] == TTTTTTCT and dna['AATG'] == AATG and dna['TCTAG'] == TCTAG and dna['GATA'] == GATA and dna['TATC'] == TATC and dna['GAAA'] == GAAA and dna['TCTG'] == TCTG:
                print(dna['name'])
        '''

    return

def find_match(db):
    match = "No Match"
    for dna in db:
        if dna['AGATC'] == AGATC and dna['TTTTTTCT'] == TTTTTTCT and dna['AATG'] == AATG and dna['TCTAG'] == TCTAG and dna['GATA'] == GATA and dna['TATC'] == TATC and dna['GAAA'] == GAAA and dna['TCTG'] == TCTG:
                match = dna['name']
    return match



def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
