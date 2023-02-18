/*
The MIT License (MIT)

Copyright © 2022,2023 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#ifdef _WIN32
#include<sys/types.h>
#include<sys/stat.h>
#define stat _stat
#else
#include <sys/stat.h>
#endif

// Get file size. returns 18446744073709551615 (uint64_t maximum value) if something went wrong
uint64_t file_size(char* path) {
    struct stat file_stats;

    if (stat(path , &file_stats) != 0) {
        return UINT64_MAX;
    }

    return (uint64_t) file_stats.st_size;
}

// Get file size by actually reading the whole file byte-by-byte until it hits EOF. Returns UINT64_MAX on open error
uint64_t file_size_brute(char* path) {
    uint64_t size = 0;
    int c = 0;
    FILE* file = NULL;

    file = fopen(path, "rb");
    if (!file) {
        return UINT64_MAX;
    }

    while((c = getc(file)) != EOF) {
        size++;
    }

    fclose(file);

    return size;
}

// Copy file at path_src to path_dst. Does not create nonexistent directories. Returns 0 in case of an error and 1 if the operation was sucessfull
int copy_file(char* path_src, char* path_dst) {
    FILE* src_file;
    FILE* dst_file;
    const uint16_t buf_size = 1024;
    uint8_t buf[buf_size];
    uint32_t bytes_processed;

    src_file = fopen(path_src, "rb");
    if (!src_file) {
        return 0;
    }

    dst_file = fopen(path_dst, "wb");
    if (!dst_file) {
        return 0;
    }

    while (!feof(src_file)) {
        bytes_processed = fread(buf, 1, buf_size, src_file);
        fwrite(buf, 1, bytes_processed, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);

    return 1;
}

// Check whether a file can be opened in read mode. Returns 0 in case of an error, 1 otherwise (successfully opened file)
int can_open_file(char* path) {
    FILE* file = NULL;

    file = fopen(path, "r");
    if (!file) {
        return 0;
    }
    fclose(file);

    return 1;
}