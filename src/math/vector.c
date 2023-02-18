/*
The MIT License (MIT)

Copyright © 2022,2023 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/* Static math definitions */

// Returns an absolute value of n
static long double absld(long double n) {
    if (n >= 0.0f) {
        return n;
    } else {
        return -n;
    }
}

// Returns the approximate result of base^exp
static long double powerl(long double base, long double exp);

static long double n_root(long double a, unsigned int n, unsigned int max_iter, long double epsilon) {
    if (n == 1 || a == 0) {
        return a;
    }

    float prev_val = 1;
    float val = 0;

    for (unsigned int i = 0; i < max_iter; i++) {
        val = (1.0 / n) * ((n - 1) * prev_val + a / powerl(prev_val, n-1));

        if (absld(prev_val - val) < epsilon) {
            return val;
        }

        prev_val = val;
    }

    return val;
}


// Returns the approximate result of base^exp
static long double powerl(long double base, long double exp) {
    // all zeroes|base is zero, but exp is not
    if ((base == 0.0f && exp == 0.0f) || (base == 0.0f && exp != 0.0f)) {
        return 0.0f;
    }

    // exp is 0
    if (exp == 0.0f) {
        return 1.0f;
    }

    // exp is negative
    if (exp < 0.0f) {
        return 1.0 / powerl(base, -exp);
    }

    // exp is in (0.0; 1.0)
    if (exp > 0.0f && exp < 1.0f) {
        return n_root(base, 1.0 / exp, 500, 0.0000000001f);
    }

    // exp is even
    if ((int) exp % 2 == 0) {
        float hpow = powerl(base, exp / 2.0f);
        return hpow * hpow;
    }

    // exp is integer
    return base * powerl(base, exp-1.0);
}

// Returns the approximate result of square root of n
static float sqrootl(long double n) {
    return powerl(n, 0.5);
}

/* End of math definitions */

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

// Calculate vector's length
long double vec2_len(vec2 vec) {
    return sqrootl((long double) (vec.x*vec.x) + (long double) (vec.y*vec.y));
}

// Calculate vector's length
long double vec2f_len(vec2f vec) {
    return sqrootl(vec.x*vec.x + vec.y*vec.y);
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
    return sqrootl(
        (long double) (vec.x*vec.x) + 
        (long double) (vec.y*vec.y) +
        (long double) (vec.z*vec.z)
    );
}

// Calculate vector's length
long double vec3f_len(vec3f vec) {
    return sqrootl(
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