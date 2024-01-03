#ifndef FILTERS_H
#define FILTERS_H

#include "image.h"

void extractComponent(const Image *source, Image *destination, char component);
void applyBlur(const Image *source, Image *destination);
void applyEdgeDetection(const Image *source, Image *destination);
void applyNoiseReduction(const Image *source, Image *destination);

#endif // FILTERS_H
