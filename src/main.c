// main.c
#include "image.h"
#include "filters.h"
#include "utils.h"
#include <stdio.h>

int main() {
    Image source, destination;
    int choice;

    printf("Enter image width: ");
    scanf("%d", &source.width);
    printf("Enter image height: ");
    scanf("%d", &source.height);
    printf("Enter image resolution: ");
    scanf("%d", &source.resolution);

    source = createImage(source.width, source.height, source.resolution);
    destination = createImage(source.width, source.height, source.resolution);

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initializeImageRandom(&source);
                break;
            case 2:
                initializeImageFromInput(&source);
                break;
            case 3:
                {
                    char filename[256];
                    printf("Enter filename: ");
                    scanf("%255s", filename);
                    initializeImageFromFile(&source, filename);
                }
                break;
            case 4:
                {
                    char component;
                    clearBuffer(); // Clear the input buffer
                    printf("Enter component (R, G, B): ");
                    scanf("%c", &component);
                    extractComponent(&source, &destination, component);
                }
                break;
            case 5:
                applyBlur(&source, &destination);
                break;
            case 6:
                applyEdgeDetection(&source, &destination);
                break;
            case 7:
                applyNoiseReduction(&source, &destination);
                break;
            case 8:
                {
                    char filename[256];
                    clearBuffer(); // Clear the input buffer
                    printf("Enter filename to save: ");
                    scanf("%255s", filename);
                    saveImageToFile(&destination, filename);
                }
                break;
            case 9:
                // Quit the program
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        // Display the modified image
        // (You might want to implement a proper display function based on your environment)
        printf("Modified Image:\n");
        // Example: Print the first 10 pixels
        for (int i = 0; i < 10; ++i) {
            printf("(%hhu, %hhu, %hhu) ", destination.data[i * 3], destination.data[i * 3 + 1], destination.data[i * 3 + 2]);
        }
        printf("\n\n");

    } while (choice != 9);

    destroyImage(&source);
    destroyImage(&destination);

    return 0;
}
