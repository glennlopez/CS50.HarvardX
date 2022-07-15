# libs to import
from cs50 import get_string


def main():
    usr_text = get_string("Text: ")

    letter_count = count_letters(usr_text)
    word_count = count_words(usr_text)
    sentence_count = count_sentences(usr_text)
    reading_level = calculate_colemanLaiuIndex(letter_count, word_count, sentence_count)

    if reading_level < 1:
        print("Before Grade 1")
    elif reading_level > 16:
        print("Grade 16+")
    else:
        print(f"Grade {round(reading_level)}")


# coleman laiu index calculator
def calculate_colemanLaiuIndex(l, w, s):
    index = float(0.0)
    L = float(l / w * 100.0)
    S = float(s / w * 100.0)
    index = round((0.0588 * L) - (0.296 * S) - 15.8)
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


# counts sentences
def count_sentences(s):
    counter = 0
    counter += s.count('!')
    counter += s.count('.')
    counter += s.count('?')

    return counter


main()
