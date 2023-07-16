#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string s = get_string("Text: ");
    float L = (float)count_letters(s) / 100;
    float S = (float)count_sentences(s) / 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int rounded_index = round(index);
    if (rounded_index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (rounded_index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade: %i\n", rounded_index);
    }

}

int count_letters(string text)
{
    int num_letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0)
        {
            num_letters++;
        }
    }
    return num_letters;
}

int count_words(string text)
{
    int num_words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]) != 0)
        {
            num_words++;
        }
    }
    return num_words;
}

int count_sentences(string text)
{
    int num_sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            num_sentences++;
        }
    }
    return num_sentences;
}