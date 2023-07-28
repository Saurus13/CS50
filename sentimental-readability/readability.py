from cs50 import get_string


def main():
    string = get_string("Text: ")
    L = 100.0 * count_letters(string) / count_words(string)
    S = 100.0 * count_sentences(string) / count_words(string)
    index = 0.0588 * L - 0.296 * S - 15.8
    # Coleman-Liau Formula
    rounded_index = round(index)  # find rounded index

    if index < 1.0:
        print("Before Grade 1")

    elif index > 16.0:
        print("Grade 16+")

    elif 1.0 < index < 16.0:
        print(f"Grade {rounded_index}")


def count_letters(text):
    num_letters = 0
    for i in range(0, len(text)):  # check if letter
        if text[i].isalpha():
            num_letters += 1
    return num_letters


def count_words(text):
    num_words = 1
    for i in range(0, len(text)):  # check if space
        if text[i].isspace():
            num_words += 1
    return num_words


def count_sentences(text):
    num_sentences = 0
    for i in range(0, len(text)):  # check if punctuation
        if text[i] == "!" or text[i] == "." or text[i] == "?":
            num_sentences += 1
    return num_sentences


main()
