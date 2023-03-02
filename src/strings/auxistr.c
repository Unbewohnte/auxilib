/*
The MIT License (MIT)

Copyright © 2023 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdlib.h>

// Returns string length not counting '\0'
unsigned long strlength(const char* str) {
    unsigned long length = 0;
    while (str[length] != '\0') {
        length++;
    }
    
    return length;
}

// Concatenate 2 strings together and return allocated resulting one
char* strconcat(const char* first, const char* second) {
    char* resulting_str = NULL;
    unsigned long first_length = strlength(first);
    unsigned long second_length = strlength(second);
    unsigned long total_length = first_length + second_length;

    resulting_str = (char*) malloc(total_length + 1);
    
    for (unsigned long i = 0; i < first_length; i++) {
        resulting_str[i] = first[i];
    }

    for (unsigned long i = 0; i < second_length; i++) {
        resulting_str[i + first_length] = second[i];
    }
    resulting_str[total_length] = '\0';
    
    return resulting_str;
}

// Check if 2 strings are equal. Returns 1 if it is true, 0 - otherwise
int streq(const char* first, const char* second) {
    unsigned long first_len = strlength(first);
    unsigned long second_len = strlength(second);

    if (first_len != second_len) {
        return 0;
    }

    for (unsigned long i = 0; i < first_len; i++) {
        if (first[i] != second[i]) {
            return 0;
        }
    }

    return 1;
}