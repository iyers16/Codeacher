#include "helpers.h"
#include  <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            RGBTRIPLE Individual_Pixel = image[i][j];

            int Grey_Average = (round((Individual_Pixel.rgbtBlue + Individual_Pixel.rgbtGreen + Individual_Pixel.rgbtRed)/3.00));
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = Grey_Average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            RGBTRIPLE Individual_Pixel = image[i][j];

            int originalRed = Individual_Pixel.rgbtRed;
            int originalGreen = Individual_Pixel.rgbtGreen;
            int originalBlue = Individual_Pixel.rgbtBlue;

            int sepiaRed  = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;

        }
    }

    return;
}

// Reflect image horizontally
void SwapPixels(RGBTRIPLE *origpixel , RGBTRIPLE *swappixel)
{
    RGBTRIPLE TempVar = *origpixel;
    *origpixel = *swappixel;
    *swappixel = TempVar;
}


void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width/2; ++j)
        {
            SwapPixels(&image[i][j] , &image[i][width-j-1]);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0;i < height; ++i)
    {

        for(int j = 0; j < width; ++j)
        {
            if(i == 0 && j == 0)
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed +image[i+1][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j+1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j+1].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j+1].rgbtBlue) / 4.0);
            }
        
            else if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i+1][j].rgbtRed + image[i][j-1].rgbtRed + image[i+1][j-1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i+1][j-1].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i+1][j-1].rgbtBlue) / 4.0);
            }
        
            else if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j+1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j+1].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue) / 4.0);
            }
        
            else if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j-1].rgbtRed) / 4.0);
                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j-1].rgbtGreen) / 4.0);
                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j-1].rgbtBlue) / 4.0);
            }
        
            else if (i == 0)
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j+1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j+1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j+1].rgbtBlue) / 6.0);
            }
        
            else if (j == 0)
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i+1][j].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j+1].rgbtRed + image[i+1][j+1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i+1][j+1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i+1][j+1].rgbtBlue) / 6.0);
            }
        
            else if (i == height - 1)
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j+1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue) / 6.0);
            }
        
            else if (j == width - 1)
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i+1][j].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j-1].rgbtRed + image[i+1][j-1].rgbtRed) / 6.0);
                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i+1][j-1].rgbtGreen) / 6.0);
                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i+1][j-1].rgbtBlue) / 6.0);
            }
            
            else
            {
                image[i][j].rgbtRed = round((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j+1].rgbtRed) / 9.0);
                image[i][j].rgbtGreen = round((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j+1].rgbtGreen) / 9.0);
                image[i][j].rgbtBlue = round((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j+1].rgbtBlue) / 9.0);
            }

        }

    }
    return;
}
