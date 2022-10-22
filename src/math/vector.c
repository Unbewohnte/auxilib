/*
The MIT License (MIT)

Copyright © 2022 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "vector.h"

// Calculate vector's length
long double vec2_len(vec2 vec) {
    return sqrtl((long double) (vec.x*vec.x) + (long double) (vec.y*vec.y));
}

// Calculate vector's length
long double vec2f_len(vec2f vec) {
    return sqrtl(vec.x*vec.x + vec.y*vec.y);
}

// Add 2 vectors together
vec2 vec2_add(vec2 a, vec2 b) {
    return (vec2){a.x+b.x, a.y+b.y};
}

// Add 2 vectors together
vec2f vec2f_add(vec2f a, vec2f b) {
    return (vec2f){a.x+b.x, a.y+b.y};
}

// Multiply 2 vectors the scalar way
long long int vec2_multiply_scalar(vec2 a, vec2 b) {
    return a.x*b.x + a.y*b.y;
}

// Multiply 2 vectors the scalar way
long double vec2f_multiply_scalar(vec2f a, vec2f b) {
    return a.x*b.x + a.y*b.y;
}

// Get cosinus of angle between 2 given vectors
long double vec2_angle(vec2 a, vec2 b) {
    return vec2_multiply_scalar(a, b) / (vec2_len(a) * vec2_len(b));
}

// Get cosinus of angle between 2 given vectors
long double vec2f_angle(vec2f a, vec2f b) {
    return vec2f_multiply_scalar(a, b) / (vec2f_len(a) * vec2f_len(b));
}

// Calculate vector's length
long double vec3_len(vec3 vec) {
    return sqrt(
        (long double) (vec.x*vec.x) + 
        (long double) (vec.y*vec.y) +
        (long double) (vec.z*vec.z)
    );
}

// Calculate vector's length
long double vec3f_len(vec3f vec) {
    return sqrtl(
        vec.x*vec.x + 
        vec.y*vec.y +
        vec.z*vec.z
    );
}

// Add 2 vectors together
vec3 vec3_add(vec3 a, vec3 b) {
    return (vec3){a.x+b.x, a.y+b.y, a.z+b.z};
}

// Add 2 vectors together
vec3f vec3f_add(vec3f a, vec3f b) {
    return (vec3f){a.x+b.x, a.y+b.y, a.z+b.z};
}

// Multiply 2 vectors the scalar way
long long int vec3_multiply_scalar(vec3 a, vec3 b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

// Multiply 2 vectors the scalar way
long double vec3f_multiply_scalar(vec3f a, vec3f b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

// Get cosinus of angle between 2 given vectors
long double vec3_angle(vec3 a, vec3 b) {
    return vec3_multiply_scalar(a, b) / (vec3_len(a) * vec3_len(b));
}

// Get cosinus of angle between 2 given vectors
long double vec3f_angle(vec3f a, vec3f b) {
    return vec3f_multiply_scalar(a, b) / (vec3f_len(a) * vec3f_len(b));
}

// | i    j    k   |
// | a.x  a.y  a.z |
// | b.x  b.y  b.z |

// Get resulting vector of vector multiplication of 2 given vectors
vec3 vec3_multiply_vector(vec3 a, vec3 b) {
    return (vec3){a.y*b.z-(b.y*a.z), -(a.x*b.z-(b.x*a.z)), a.x*b.y-(b.x*a.y)};
}

// Get resulting vector of vector multiplication of 2 given vectors
vec3f vec3f_multiply_vector(vec3f a, vec3f b) {
    return (vec3f){a.y*b.z-(b.y*a.z), -(a.x*b.z-(b.x*a.z)), a.x*b.y-(b.x*a.y)};
}