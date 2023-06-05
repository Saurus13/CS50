#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start Size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End Size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int n = 0; //number of years
    while(start < end){
        start =  (float)start/3;
        start -= (float)start/4;
        n++;
        printf("%i\n", start);
    }
    // TODO: Print number of years
    printf("The number of years is %i\n", n);

}
