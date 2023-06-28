#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: ");
    for (int i = 0; i < strlen(message); i++) //dec to bin convertor
    {
        int bits[8];
        for(int j = 0; j < 8; j++)
        {
            char x = message[i];
            if (x % 2 == 0)
            {
                bits[j] = 0;
            }
            else
            {
                bits[j] = 1;
            }
            x = floor(x/2);
        }
    }

    // TODO
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
