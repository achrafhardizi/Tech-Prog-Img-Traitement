#include "utils.h"
#include <stdio.h>

void printMenu()
{
    printf("1. Initialize image with random values\n");
    printf("2. Initialize image from keyboard input\n");
    printf("3. Initialize image from file\n");
    printf("4. Extract image component (R, G, B)\n");
    printf("5. Apply blur filter\n");
    printf("6. Apply edge detection filter\n");
    printf("7. Apply noise reduction filter\n");
    printf("8. Save image to file\n");
    printf("9. Quit\n");
}

void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
