#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define SIZE 512

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

    char* inputFile = argv[1];
    if (input_file == NULL) //check if file is valid
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    //initialization
    FILE* inputPtr = fopen(inputFile, "r");
    char filename[8]; // 8 chars in '000.jpg\0'
    FILE* outputPtr = NULL;
    uint8_t buffer[SIZE];
    int counter = 0;

    while (feof(inputPtr) == 0 || fread(buffer, sizeof(uint8_t), SIZE, inputPtr))
    {
        if (isHeader(buffer)) //creating new jpg in file
        {
            if (outputPtr != NULL)
            {
                fclose(outputPtr);
            }
            //first time code runs
            sprintf(filename, "%03i.jpg", counter);
            outputPtr = fopen(filename, "w");
            counter++;
        }

        if (outputPtr != NULL) //writing
        {
            fwrite(buffer, sizeof(buffer), 1, outputPtr);
        }
    }
    if (inputPtr == NULL)
    {
        fclose(inputPtr);
    }
    if (outputPtr == NULL)
    {
        fclose(outputPtr);
    }

    return 0;
}