// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1]; //+1 for /0
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26; //A - Z (26 letters)

// Hash table
node *table[N];

//New Variables
unsigned int count;
unsigned int hashVal;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long sum = 0;
    int i = 0;
    while (i < strlen(word)) //add all ASCII values of word to 'total'
    {
        sum += tolower(word[i]);
        i++;
    }

    return sum % N; //obtain hash value
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL) //if file cannot be opened, return false
    {
        printf("Cannot open %s\n", dictionary);
        return false;
    }
    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF) //read until end of file
    {
        node *n = malloc(sizeof(node)); //create new node
        if (n == NULL) //if malloc returns NULL
        {
            return false;
        }

        //Copy word to node
        strcpy(n->word, word);
        hashVal = hash(word);
        n->next = table[hashVal];
        table[hashVal] = n;
        count++; //word counter
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (count > 0);
    {
        return count; //determined in 'load' function
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
