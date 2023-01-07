/*
The MIT License (MIT)

Copyright © 2023 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef CVEC_H
#define CVEC_H

#include <stdlib.h>

// Basic vector structure 
typedef struct cvec {
    size_t cap;
    size_t size;
    size_t data_size;
    char* contents;
} cvec;

// Create new vector with the maximum data elements of cap where data is data_size bytes long 
cvec cvec_new(size_t data_size, size_t cap);

// Deallocate vector's contents
void cvec_free(cvec* vec);

// Put data at the end of the vector
void cvec_put(cvec* vec, const void* data);

// Get data at the specified index. Returns NULL if out of bounds
char* cvec_at(cvec* vec, size_t index);

// Pop the last data element
void cvec_pop(cvec* vec);

// Remove data element at specified index and shift data to left if necessary
void cvec_remove(cvec* vec, size_t index);

#endif