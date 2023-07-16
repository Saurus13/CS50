#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);

int main(void)
{
    string s = get_string("Text: ");
    printf("Letters: %i\n", count_letters(s));
}

int count_letters(string text)
{
    int num_letters = 0;
    for (int i = 0, int n = strlen(text); i < n; i++)
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
    for (int i = 0, int n = strlen(text); i < n; i++)
    {
        if (isspace(text[i] != ))
    }
}