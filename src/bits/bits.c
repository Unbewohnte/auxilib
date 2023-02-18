/*
The MIT License (MIT)

Copyright © 2022,2023 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdint.h>

// Returns 1 if position bit in byte is 1, 0 if 0; -1 is returned in case position is not in range [1..8].
// Position is counted from the least significant bit, ie: in 10010010 position 1 is "0", but position 8 is "1" 
int8_t get_byte_bit(uint8_t byte, uint8_t position) {
    if (position > 8 || position < 1) {
        return -1;
    }

    return ((1 << (position-1)) & byte);
}


// Sets position bit in byte to 1. Does nothing if position is not in range [1..8] or if the bit is already 1.
// Position is counted from the least significant bit, ie: in 10010010 position 1 is "0", but position 8 is "1" 
void set_byte_bit(uint8_t* byte, uint8_t position) {
    if (position > 8 || position < 1) {
        return;
    }

    *byte = (*byte | ((uint8_t) (1 << (position-1))));
}

// Sets position bit in byte to 0. Does nothing if position is not in range [1..8] or if the bit is already 0.
// Position is counted from the least significant bit, ie: in 10010010 position 1 is "0", but position 8 is "1" 
void unset_byte_bit(uint8_t* byte, uint8_t position) {
    if (position > 8 || position < 1) {
        return;
    }
    
    *byte = (*byte & ~(1 << (position-1)));
}