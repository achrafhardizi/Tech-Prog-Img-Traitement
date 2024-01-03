#ifndef IMAGE_H
#define IMAGE_H

typedef struct {
    int width;
    int height;
    int resolution;
    unsigned char *data;
} Image;

Image createImage(int width, int height, int resolution);
void initializeImageRandom(Image *image);
void initializeImageFromInput(Image *image);
void initializeImageFromFile(Image *image, const char *filename);
void saveImageToFile(const Image *image, const char *filename);
void destroyImage(Image *image);

#endif // IMAGE_H
