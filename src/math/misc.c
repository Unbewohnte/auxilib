/*
The MIT License (MIT)

Copyright © 2023 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

// Returns an absolute value of n
char absch(char n) {
    if (n >= 0) {
        return n;
    } else {
        return -n;
    }
}

// Returns an absolute value of n
short abssh(short n) {
    if (n >= 0) {
        return n;
    } else {
        return -n;
    }
}

// Returns an absolute value of n
int absi(int n) {
    if (n >= 0) {
        return n;
    } else {
        return -n;
    }
}

// Returns an absolute value of n
long absl(long n) {
    if (n >= 0) {
        return n;
    } else {
        return -n;
    }
}

// Returns an absolute value of n
long long absll(long long n) {
    if (n >= 0) {
        return n;
    } else {
        return -n;
    }
}

// Returns an absolute value of n
float absf(float n) {
    if (n >= 0.0f) {
        return n;
    } else {
        return -n;
    }
}

// Returns an absolute value of n
double absd(double n) {
    if (n >= 0.0f) {
        return n;
    } else {
        return -n;
    }
}

// Returns an absolute value of n
long double absld(long double n) {
    if (n >= 0.0f) {
        return n;
    } else {
        return -n;
    }
}

// Returns the approximate result of base^exp
float powerf(float base, float exp);

// Returns the approximate result of base^exp
long double powerl(long double base, long double exp);

long double n_root(long double a, unsigned int n, unsigned int max_iter, long double epsilon) {
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
float powerf(float base, float exp) {
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
        return 1.0 / powerf(base, -exp);
    }

    // exp is in (0.0; 1.0)
    if (exp > 0.0f && exp < 1.0f) {
        return (float) n_root(base, 1.0 / exp, 500, 0.00001f);
    }

    // exp is even
    if ((int) exp % 2 == 0) {
        float hpow = powerf(base, exp / 2.0f);
        return hpow * hpow;
    }

    // exp is integer
    return base * powerf(base, exp-1.0);
}

// Returns the approximate result of base^exp
long double powerl(long double base, long double exp) {
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
float sqrootf(float n) {
    return powerf(n, 0.5f);
}

// Returns the approximate result of square root of n
float sqrootl(long double n) {
    return powerl(n, 0.5);
}