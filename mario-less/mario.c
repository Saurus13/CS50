#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt user for height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8); //height must be between 1 and 8 inclusive

    //Print image
    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++) //print height-i blanks
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++) //print number of #
        {
            printf("#");
        }
        printf("\n"); //new line
    }
}