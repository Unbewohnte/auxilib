/*
The MIT License (MIT)

Copyright © 2022 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "endian.h"

// Determines this machine's endianness. Returns 0 in case it is of Big-Endian type, 1 - Little-Endian
int endianness() {
    // 00000000 00000001
    int16_t n = 1;
    if (*(uint8_t*) &n == 1) {
        // 00000001
        return 1;
    } else {
        // 00000000
        return 0;
    }
}

// Swaps 16bit integer's endianness
uint16_t swap_endian16(uint16_t num) {
    return (uint16_t) 
    (
        ((num >> 8) & 0x00FF) |
        ((num << 8) & 0xFF00)
    );
}

// Swaps 32bit integer's endianness
uint32_t swap_endian32(uint32_t num) {
    return (uint32_t)
    (
        ((num << 24)  & 0xFF000000) |
        ((num << 8)   & 0x00FF0000) |
        ((num >> 8)   & 0x0000FF00) |
        ((num >> 24)  & 0x000000FF)
    );
}

// Swaps 64bit integer's endianness
uint64_t swap_endian64(uint64_t num) {
    return (uint64_t)
    (
        ((num << 56)  & 0xFF00000000000000) |
        ((num << 40)  & 0x00FF000000000000) |
        ((num << 24)  & 0x0000FF0000000000) |
        ((num << 8)   & 0x000000FF00000000) |
        ((num >> 8)   & 0x00000000FF000000) |
        ((num >> 24)  & 0x0000000000FF0000) |
        ((num >> 40)  & 0x000000000000FF00) |
        ((num >> 56)  & 0x00000000000000FF)
    );
}