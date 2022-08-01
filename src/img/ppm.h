/*
The MIT License (MIT)

Copyright © 2022 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

// 8bit Red-Green-Blue color representation
typedef struct rgb8 {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb8;

// Minimal ppm image structure
typedef struct ppm_image {
    unsigned int width;
    unsigned int height;
    rgb8* pixels;
} ppm_image;

// Read ppm image from file on the disk. Returns NULL if something went wrong
ppm_image* read_ppm(const char* path);

// Write ppm image to the disk. Returns 0 if everything is alright, 1 otherwise
int write_ppm(const ppm_image* ppm, const char* path);

// Put pixel with specified rgb8 color at x,y coordinates. Returns 0 if pixel has been replaced, 1 if 
// coordinates are out of bounds
int put_pixel_at(const unsigned int x, const unsigned int y, const rgb8 color, ppm_image* ppm);

// Get pixel color at specified coordinates. Returns a const pointer to that pixel color if 
// it is present, NULL if coordinates are out of bounds
const rgb8* get_pixel_at(const unsigned int x, const unsigned int y, ppm_image* ppm);

// Create a new ppm image with specified dimensions. All pixels are {0, 0, 0} (black) by default
ppm_image* new_ppm_image(const unsigned int width, const unsigned int height);