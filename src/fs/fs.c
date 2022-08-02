/*
The MIT License (MIT)

Copyright © 2022 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "fs.h"

// Get file size. returns 18446744073709551615 (uint64_t maximum value) if something went wrong
uint64_t file_size(char* path) {
    FILE* file_stream;
    uint64_t file_size;

    file_stream = fopen(path, "rb");
    if (!file_stream) {
        return UINT64_MAX;
    }

    fseek(file_stream, 0, SEEK_END);
    file_size = ftell(file_stream);
    fseek(file_stream, 0, SEEK_SET);

    fclose(file_stream);

    return file_size;
}

// Copy file at path_src to path_dst. Does not create nonexistent directories. Returns EXIT_FAILURE in case of an error
int copy_file(char* path_src, char* path_dst) {
    FILE* src_file;
    FILE* dst_file;
    const uint16_t buf_size = 1024;
    uint8_t buf[buf_size];
    uint32_t bytes_processed;

    src_file = fopen(path_src, "rb");
    if (!src_file) {
        return EXIT_FAILURE;
    }

    dst_file = fopen(path_dst, "wb");
    if (!dst_file) {
        return EXIT_FAILURE;
    }

    while (!feof(src_file)) {
        bytes_processed = fread(buf, 1, buf_size, src_file);
        fwrite(buf, 1, bytes_processed, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);

    return EXIT_SUCCESS;
}