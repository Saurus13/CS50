from cs50 import get_string

def main():
    string = get_string("Text: ")
    L = 100.0 * count_letters(string) / count_words(string)
    S = 100.0 * count_sentences(string) / count_words(string)
    index = 0.0588 * L - 0.296 * S - 15.8; # Coleman-Liau Formula

    if index < 1.0:
        printf("Before Grade 1\n")

    elif index > 16.0:
        printf("Grade 16+\n")

    elif 1.0 < index < 16.0:
        printf("Grade %i\n", rounded_index)

def count_letters(string):
    num_letters = 0
    for i in range(0, len(string)) # check if letter
    {
        if string[i].isalpha()
        {
            num_letters++;
        }
    }
    return num_letters;

main()