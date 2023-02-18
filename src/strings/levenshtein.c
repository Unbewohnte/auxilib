/*
The MIT License (MIT)

Copyright © 2023 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <string.h>

int _min(int a, int b) {
    if (a < b) {
        return a;
    }

    return b;
}

// Calculates Levenshtein distance for str1 and str2 of length len1 and len2 respectively
int levenshtein_distance(const char* str1, const char* str2) {
    unsigned int len1 = strlen(str1) + 1;
    unsigned int len2 = strlen(str2) + 1;

    if (len1 == 0) {
        return len2;
    }

    if (len2 == 0) {
        return len1;
    }

    if (strcmp(str1, str2) == 0) {
        return 0;
    }

    char s1[len2];
    char s2[len2];
    char row[len1];

    strcpy(s1, str1);
    strcpy(s2, str2);

    for (unsigned int i = 0; i < len1; i++) {
        row[i] = i;
    }

    for (unsigned int i = 1; i < len2; i++) {
        int previous = i;

        for (unsigned int j = 1; j < len1; j++) {
            int current = row[j-1];
            if (s2[i-1] != s1[j-1]) {
                current = _min(_min(row[j-1]+1, previous+1), row[j]+1);
            }
            row[j-1] = previous;
            previous = current;
        }
        row[len1] = previous;
    }

    return row[len1];
}