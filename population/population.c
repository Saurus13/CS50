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
    while (n < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End Size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int n = 0; //number of years
    for(int i = 0; i <= end; i++){
        start += start/3;
        start -= start/4
        n++;
    }
    // TODO: Print number of years
    

}
