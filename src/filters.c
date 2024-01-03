#include <stdio.h>
#include "filters.h"

void extractComponent(const Image *source, Image *destination, char component)
{
    // Example: Extracting the red component
    int componentIndex = 0;
    switch (component)
    {
    case 'R':
    case 'r':
        componentIndex = 0;
        break;
    case 'G':
    case 'g':
        componentIndex = 1;
        break;
    case 'B':
    case 'b':
        componentIndex = 2;
        break;
    default:
        fprintf(stderr, "Invalid component: %c\n", component);
        return;
    }

    for (int i = 0; i < source->width * source->height; ++i)
    {
        destination->data[i * 3 + componentIndex] = source->data[i * 3 + componentIndex];
    }
}

void applyBlur(const Image *source, Image *destination)
{
    // Example: Simple box blur
    // (Note: This is a naive implementation and may not produce the best visual results)
    for (int i = 0; i < source->width * source->height * 3; ++i)
    {
        int sum = source->data[i];
        int count = 1;

        if ((i + 1) % 3 != 0)
        { // Not at the end of the pixel (R, G, B) triplet
            sum += source->data[i + 3];
            count++;
        }

        if (i >= 3)
        { // Not at the beginning of the pixel (R, G, B) triplet
            sum += source->data[i - 3];
            count++;
        }

        destination->data[i] = sum / count;
    }
}

void applyEdgeDetection(const Image *source, Image *destination)
{
    // Example: Simple edge detection using a basic convolution kernel
    // (Note: This is a naive implementation and may not produce the best visual results)
    // Example kernel:
    //   -1 -1 -1
    //   -1  8 -1
    //   -1 -1 -1
    for (int i = 1; i < source->height - 1; ++i)
    {
        for (int j = 1; j < source->width - 1; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                int sum = 8 * source->data[(i * source->width + j) * 3 + k];
                sum -= source->data[((i - 1) * source->width + j - 1) * 3 + k];
                sum -= source->data[((i - 1) * source->width + j) * 3 + k];
                sum -= source->data[((i - 1) * source->width + j + 1) * 3 + k];
                sum -= source->data[(i * source->width + j - 1) * 3 + k];
                sum -= source->data[(i * source->width + j + 1) * 3 + k];
                sum -= source->data[((i + 1) * source->width + j - 1) * 3 + k];
                sum -= source->data[((i + 1) * source->width + j) * 3 + k];
                sum -= source->data[((i + 1) * source->width + j + 1) * 3 + k];

                destination->data[(i * source->width + j) * 3 + k] = sum;
            }
        }
    }
}

void applyNoiseReduction(const Image *source, Image *destination)
{
    // Example: Simple noise reduction using median filtering
    // (Note: This is a naive implementation and may not produce the best visual results)
    for (int i = 1; i < source->height - 1; ++i)
    {
        for (int j = 1; j < source->width - 1; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                unsigned char values[9] = {
                    source->data[((i - 1) * source->width + j - 1) * 3 + k],
                    source->data[((i - 1) * source->width + j) * 3 + k],
                    source->data[((i - 1) * source->width + j + 1) * 3 + k],
                    source->data[(i * source->width + j - 1) * 3 + k],
                    source->data[(i * source->width + j) * 3 + k],
                    source->data[(i * source->width + j + 1) * 3 + k],
                    source->data[((i + 1) * source->width + j - 1) * 3 + k],
                    source->data[((i + 1) * source->width + j) * 3 + k],
                    source->data[((i + 1) * source->width + j + 1) * 3 + k]};

                // Sort values
                for (int p = 0; p < 9 - 1; ++p)
                {
                    for (int q = 0; q < 9 - p - 1; ++q)
                    {
                        if (values[q] > values[q + 1])
                        {
                            // Swap values
                            unsigned char temp = values[q];
                            values[q] = values[q + 1];
                            values[q + 1] = temp;
                        }
                    }
                }

                // Assign the median value to the destination pixel
                destination->data[(i * source->width + j) * 3 + k] = values[4];
            }
        }
    }
}
