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
    AGATC_row = 0
    TTTTTTCT_row = 0
    AATG_row = 0
    TCTAG_row = 0
    GATA_row = 0
    TATC_row = 0
    GAAA_row = 0
    TCTG_row = 0

    with open(database) as db_file:
        reader = csv.DictReader(db_file)
        for row in reader:

            # check if the key exists in database
            if 'AGATC' in row:
                AGATC_row = int(row['AGATC'])
            if 'TTTTTTCT' in row:
                TTTTTTCT_row = int(row['TTTTTTCT'])
            if 'AATG' in row:
                AATG_row = int(row['AATG'])
            if 'TCTAG' in row:
                TCTAG_row = int(row['TCTAG'])
            if 'GATA' in row:
                GATA_row = int(row['GATA'])
            if 'TATC' in row:
                TATC_row = int(row['TATC'])
            if 'GAAA' in row:
                GAAA_row = int(row['GAAA'])
            if 'TCTG' in row:
                TCTG_row = int(row['TCTG'])

            dna = {'name': row['name'], 'AGATC': AGATC_row, 'TTTTTTCT': TTTTTTCT_row, 'AATG': AATG_row,
                   'TCTAG': TCTAG_row, 'GATA': GATA_row, 'TATC': TATC_row, 'GAAA': GAAA_row, 'TCTG': TCTG_row}
            dna_db.append(dna)

    # TODO: Read DNA sequence file into a variable
    sq_file = open(sequence, 'r')
    sequence_file = sq_file.read()

    # TODO: Find longest match of each STR in DNA sequence
    global AGATC, TTTTTTCT, AATG, TCTAG, GATA, TATC, GAAA, TCTG
    AGATC = longest_match(sequence_file, 'AGATC')
    TTTTTTCT = longest_match(sequence_file, 'TTTTTTCT')
    AATG = longest_match(sequence_file, 'AATG')
    TCTAG = longest_match(sequence_file, 'TCTAG')
    GATA = longest_match(sequence_file, 'GATA')
    TATC = longest_match(sequence_file, 'TATC')
    GAAA = longest_match(sequence_file, 'GAAA')
    TCTG = longest_match(sequence_file, 'TCTG')

    # TODO: Check database for matching profiles
    # for small database
    if database.find('small') > 0:
        print(find_small_match(dna_db))

    # for large database
    if database.find('large') > 0:
        print(find_large_match(dna_db))

    return


# returns a match or no match
def find_large_match(db):
    match = "No match"
    for dna in db:
        if dna['AGATC'] == AGATC and dna['TTTTTTCT'] == TTTTTTCT and dna['AATG'] == AATG and dna['TCTAG'] == TCTAG and dna['GATA'] == GATA and dna['TATC'] == TATC and dna['GAAA'] == GAAA and dna['TCTG'] == TCTG:
            match = dna['name']
    return match


# returns a match or no match
def find_small_match(db):
    match = "No match"
    for dna in db:
        if dna['AGATC'] == AGATC and dna['AATG'] == AATG and dna['TATC'] == TATC:
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
