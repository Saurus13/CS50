#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string s = get_string("Text: ");
    float L = (float)count_letters(s)/100;
    float S = (float)count_sentences(s)/100;
    if ()
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