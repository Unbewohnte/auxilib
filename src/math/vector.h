/*
The MIT License (MIT)

Copyright © 2022 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <math.h>

typedef struct vec2 {
    long long int x;
    long long int y;
} vec2;

typedef struct vec2f {
    long double x;
    long double y;
} vec2f;

// Calculate vector's length
long double vec2_len(vec2 vec);

// Calculate vector's length
long double vec2f_len(vec2f vec);

// Multiply 2 vectors the scalar way
long long int vec2_multiply_scalar(vec2 a, vec2 b);

// Multiply 2 vectors the scalar way
long double vec2f_multiply_scalar(vec2f a, vec2f b);

// Add 2 vectors together
vec2 vec2_add(vec2 a, vec2 b);

// Add 2 vectors together
vec2f vec2f_add(vec2f a, vec2f b);

// Get cosinus of angle between 2 given vectors
long double vec2_angle(vec2 a, vec2 b);

// Get cosinus of angle between 2 given vectors
long double vec2f_angle(vec2f a, vec2f b);

typedef struct vec3 {
    long long int x;
    long long int y;
    long long int z;
} vec3;

typedef struct vec3f {
    long double x;
    long double y;
    long double z;
} vec3f;

// Calculate vector's length
long double vec3_len(vec3 vec);

// Calculate vector's length
long double vec3f_len(vec3f vec);

// Add 2 vectors together
vec3 vec3_add(vec3 a, vec3 b);

// Add 2 vectors together
vec3f vec3f_add(vec3f a, vec3f b);

// Multiply 2 vectors the scalar way
long long int vec3_multiply_scalar(vec3 a, vec3 b);

// Multiply 2 vectors the scalar way
long double vec3f_multiply_scalar(vec3f a, vec3f b);

// Get cosinus of angle between 2 given vectors
long double vec3_angle(vec3 a, vec3 b);

// Get cosinus of angle between 2 given vectors
long double vec3f_angle(vec3f a, vec3f b);

// Get resulting vector of vector multiplication of 2 given vectors
vec3 vec3_multiply_vector(vec3 a, vec3 b);

// Get resulting vector of vector multiplication of 2 given vectors
vec3f vec3f_multiply_vector(vec3f a, vec3f b);