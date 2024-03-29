/*
The MIT License (MIT)

Copyright © 2023 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

// Returns string length not counting '\0'
unsigned long strlength(const char* str);

// Concatenate 2 strings together and return allocated resulting one
char* strconcat(const char* first, const char* second);

// Concatenate 2 strings together up to n-th char and return allocated resulting one
char* strnconcat(const char* first, const char* second, unsigned long n);

// Check if 2 strings are equal. Returns 1 if it is true, 0 - otherwise
int streq(const char* first, const char* second);