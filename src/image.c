#include "image.h"
#include <stdlib.h>
#include <stdio.h>

Image createImage(int width, int height, int resolution)
{
    Image img;
    img.width = width;
    img.height = height;
    img.resolution = resolution;
    img.data = (unsigned char *)malloc(width * height * 3 * sizeof(unsigned char));
    return img;
}

void initializeImageRandom(Image *image)
{
    // Example: Filling the image with random values
    for (int i = 0; i < image->width * image->height * 3; ++i)
    {
        image->data[i] = rand() % 256; // Random value between 0 and 255
    }
}

void initializeImageFromInput(Image *image)
{
    // Example: Filling the image with user input values
    for (int i = 0; i < image->width * image->height * 3; ++i)
    {
        printf("Enter value for pixel %d: ", i);
        scanf("%hhu", &image->data[i]);
    }
}

void initializeImageFromFile(Image *image, const char *filename)
{
    // Example: Reading image data from a file
    FILE *file = fopen(filename, "rb");
    if (file != NULL)
    {
        fread(image->data, sizeof(unsigned char), image->width * image->height * 3, file);
        fclose(file);
    }
    else
    {
        fprintf(stderr, "Error opening file: %s\n", filename);
    }
}

void saveImageToFile(const Image *image, const char *filename)
{
    // Example: Writing image data to a file
    FILE *file = fopen(filename, "wb");
    if (file != NULL)
    {
        fwrite(image->data, sizeof(unsigned char), image->width * image->height * 3, file);
        fclose(file);
    }
    else
    {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
    }
}

void destroyImage(Image *image)
{
    free(image->data);
    image->data = NULL;
}
