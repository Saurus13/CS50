#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg = 0;
    int rounded = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0;
            rounded = round(avg);
            image[i][j].rgbtRed = rounded;
            image[i][j].rgbtBlue = rounded;
            image[i][j].rgbtGreen = rounded;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed = 0;
    int sepiaBlue = 0;
    int sepiaGreen = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtBlue + .189 * image[i][j].rgbtGreen);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtBlue + .131 * image[i][j].rgbtGreen);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtBlue + .168 * image[i][j].rgbtGreen);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < floor(width / 2); j++)
        {
            int tmp1 = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width-j].rgbtRed;
            image[i][width-j].rgbtRed = tmp1;

            int tmp2 = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width-j].rgbtBlue;
            image[i][width-j].rgbtBlue = tmp2;

            int tmp3 = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width-j].rgbtGreen;
            image[i][width-j].rgbtGreen = tmp3;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

        }
    }
    return;
}
