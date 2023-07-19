#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define SIZE 512;

bool isHeader (uint8_t buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}

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
    typedef uint8_t BYTE;
    int counter = 0;

    while (feof(inputPtr) == 0 || fread(buffer, BYTE, SIZE, inputPtr))
    {
        if (isHeader(buffer) == true)
        {
            sprintf(filename, "03a.jpg", counter);
            outputPtr = fopen(filename, "w");
            counter++;
        }
    }

    return 0;
}