#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define SIZE 512;

int main(int argc, char *argv[])
{
    if (argc != 2) //check if user runs program in valid manner
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    char* input_file = argv[1];
    /*if (input_file == NULL) //check if file is valid
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }*/

    //initialization
    FILE* inputPtr = fopen(input_file, "r");
    char filename[8]; // 8 chars in '000.jpg\0'
    FILE* outputPtr = NULL;
    uint8_t buffer[SIZE];
    int counter = 0;

    



    return 0;
}