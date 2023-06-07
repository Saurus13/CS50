#include <cs50.h>
#include <stdio.h>

int main()
{
    // TODO
    int cents;
    do
    {
        cents = get_int("How many cents? ");
    }
    while (cents < 0);

    // TODO
    int quarters = 0;
    for (int i = 1; i <= cents; i++)
    {
        if (i % 25 == 0)
        {
            quarters++;
        }
    }
    printf("Quarters: %i", quarters);
}