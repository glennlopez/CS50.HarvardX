# libs to import
from cs50 import get_string

def main():
    test = get_string("Text: ")

    letter_count = count_letters(test) #debug
    word_count = count_words(test) #debug
    sentence_count = count_sentences(test) #debug
    reading_level = calculate_colemanLaiuIndex(letter_count, word_count, sentence_count)

    print(f"letter counter: {letter_count}")
    print(f"word counter: {word_count}")
    print(f"sentence counter: {sentence_count}")
    print(f"reading level: {reading_level}")

# coleman laiu index calculator
def calculate_colemanLaiuIndex(l, w, s):
    index = float(0.0)
    L = float(l / w * 100.0)
    S =  float(s / w * 100.0)
    index = round((0.0588 * L) - (0.296 * S) - 15.8);
    return float(index)

# count letters
def count_letters(s):
    counter = 0
    for char in s:
        if char.isalpha():
            counter += 1
    return counter

# count words
def count_words(s):
    counter = 0
    for char in s:
        if char == " ":
            counter += 1
    if counter > 0:
        counter += 1
    return counter

def count_sentences(s):
    counter = 0
    counter += s.count('!')
    counter += s.count('.')
    counter += s.count('?')

    return counter

main()
