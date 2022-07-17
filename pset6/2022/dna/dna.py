import csv
import sys


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
    with open(database) as db_file:
        reader = csv.DictReader(db_file)
        for row in reader:
            dna = {'name':row['name'], 'AGATC':int(row['AGATC']), 'AATG':int(row['AATG']), 'TATC':int(row['TATC'])}
            dna_db.append(dna)


    # TODO: Read DNA sequence file into a variable
    sq_file = open(sequence, 'r')
    sequence_file = sq_file.read()

    # TODO: Find longest match of each STR in DNA sequence
    AGATC = sequence_file.count('AGATC')
    AATG = sequence_file.count('AATG')
    TATC = sequence_file.count('TATC')

    #debug
    print(f"AGATC {AGATC}")
    print(f"AATG {AATG}")
    print(f"TATC {TATC}")

    # TODO: Check database for matching profiles
    for dna in dna_db:
        #print(f"{dna['name']}, {dna['AGATC']}, {dna['AATG']}, {dna['TATC']}")
        if dna['AGATC'] == AGATC and dna['AATG'] == AATG and dna['TATC'] == TATC:
            print(f"Match found: {dna['name']}")

    return


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
