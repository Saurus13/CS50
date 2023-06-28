#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //string name = get_string("What is your name? "); //ask for user's name
    //printf("hello, %s\n", name); //print name
    printf("%i", ' '/2);

    int x = 72;
    int bits[8];
    while(x != 0)
    {
        int i = 0;
        if(x % 2 == 0)
        {
            bits[i] = 0;
            i++;
        }
        else
        {
            bits[i] = 1;
            i++;
        }
        x = floor(x/2);
    }

    for(int i = 0; i < 8; i++)
    {
        printf("%i", bits[i]);
    }
    printf("\n");
}