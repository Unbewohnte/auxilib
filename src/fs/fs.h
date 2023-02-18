/*
The MIT License (MIT)

Copyright © 2022,2023 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdint.h>

// Get file size. returns 18446744073709551615 (uint64_t maximum value) if something went wrong
uint64_t file_size(char* path);

// Get file size by actually reading the whole file byte-by-byte until it hits EOF. Returns UINT64_MAX on open error
uint64_t file_size_brute(char* path);

// Copy file at path_src to path_dst. Does not create nonexistent directories. Returns 0 in case of an error and 1 if the operation was sucessfull
int copy_file(char* path_src, char* path_dst);

// Check whether a file can be opened in read mode. Returns 0 in case of an error, 1 otherwise (successfully opened file)
int can_open_file(char* path);