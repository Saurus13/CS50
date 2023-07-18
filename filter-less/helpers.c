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
        for (int j = 0; j < width; j++) //find average value of rgb and apply to each pixel
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
        for (int j = 0; j < width; j++) //find colour values for sepia
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtBlue + .189 * image[i][j].rgbtGreen);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtBlue + .131 * image[i][j].rgbtGreen);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtBlue + .168 * image[i][j].rgbtGreen);
            if (sepiaRed > 255) //if exceed, set to 255
            {
                image[i][j].rgbtRed = 255;
            }
            if (sepiaBlue > 255) //if exceed, set to 255
            {
                image[i][j].rgbtBlue = 255;
            }
            if (sepiaGreen > 255) //if exceed, set to 255
            {
                image[i][j].rgbtGreen = 255;
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
        for (int j = 0; j < (width / 2); j++) //swap until reaching halfway through width
        {
            int tmp1 = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width-j-1].rgbtRed;
            image[i][width-j-1].rgbtRed = tmp1;

            int tmp2 = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width-j-1].rgbtBlue;
            image[i][width-j-1].rgbtBlue = tmp2;

            int tmp3 = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width-j-1].rgbtGreen;
            image[i][width-j-1].rgbtGreen = tmp3;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width]; //copy of original image

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumBlue = 0;
            int sumGreen = 0;
            float count = 0.0;
            for (int k = -1; k < 2; k++) //check for edge cases
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k < 0 || i + k > height - 1 || j + l < 0 || j + l > width - 1) //if edge, skip counting rgb
                    {
                        continue;
                    }
                    sumRed += image[i+k][j+l].rgbtRed;
                    sumBlue += image[i+k][j+l].rgbtBlue;
                    sumGreen += image[i+k][j+l].rgbtGreen;
                    count++; //keep track of how many tiles we are averaging
                }
            }
            copy[i][j].rgbtRed = round(sumRed / count);
            copy[i][j].rgbtBlue = round(sumBlue / count);
            copy[i][j].rgbtGreen = round(sumGreen / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
        }
    }
    return;
}
