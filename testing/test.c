/*
The MIT License (MIT)

Copyright © 2022 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdint.h>
#include <stddef.h>

#include "../src/rng/lcg.c"
#include "../src/rng/xorshift.c"
#include "../src/rng/bbs.c"

#include "../src/img/ppm.c"

#include "../src/endian/endian.c"

int test_rng() {
    lcg(76);
    xorshift32(753);
    bbs(11241);
    
    return EXIT_SUCCESS;
}

int test_ppm() {
    ppm_image* ppm = read_ppm("test_img512x512.ppm");
    if (ppm == NULL) {
        printf("[ERROR] failled to read test PPM image\n");
        return EXIT_FAILURE;
    }

    if (write_ppm(ppm, "result_image.ppm") != 0) {
        printf("[ERROR] failed to write new ppm image\n");
        return EXIT_FAILURE;
    }

    free(ppm);

    ppm_image* new_ppm = new_ppm_image(200, 200);
    for(int y = 0; y < 200; y++) {
        for(int x = 0; x < 200; x++) {
            rgb8 pixel = {x + 10, y + 10, 55 + y};
            put_pixel_at(x, y, pixel, new_ppm);
        }
    }

    if (write_ppm(new_ppm, "result_image.ppm") != 0) {
        printf("[ERROR] failed to write new changed ppm image\n");
        return EXIT_FAILURE;
    }

    free(new_ppm);

    return EXIT_SUCCESS;
}

int test_img() {
    if (test_ppm() == EXIT_FAILURE) {
        printf("[INFO] PPM test failed\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int test_endian() {
    if (endianness() == 0) {
        printf("[INFO] This machine is determined to be of Big-Endian type; Test's failed if that's not the case\n");
    } else {
        printf("[INFO] This machine is determined to be of Little-Endian type; Test's failed if that's not the case\n");
    }

    // 01100001 10101000
    const uint16_t test_num16 = 25000;
    // 10101000 01100001
    const uint16_t test_num16_swapped = 43105;
    if (swap_endian16(test_num16) != test_num16_swapped) {
        printf("[INFO] Failed to swap endianness for 16bit integer: %u -> %u; supposed to get %u\n",
            test_num16, swap_endian16(test_num16), test_num16_swapped
        );
        return EXIT_FAILURE;
    }

    // 00000000 01101110 11101110 11110101
    const uint32_t test_num32 = 7270133;
    // 11110101 11101110 01101110 00000000
    const uint32_t test_num32_swapped = 4126043648;
    if ((swap_endian32(test_num32)) != test_num32_swapped) {
        printf("[INFO] Failed to swap endianness for 32bit integer: %u -> %u; supposed to get %u\n",
            test_num32, swap_endian32(test_num32), test_num32_swapped
        );
        return EXIT_FAILURE;
    }

    // 00000000 00000000 11010110 00000000 10010111 10001111 00000000 00000000
    const uint64_t test_num64 = 235298031075328;

    // 11110101 10011110 10001111 00000000 00000000 00000000 00000000 00000000
    const uint64_t test_num64_swapped = 157878716858368;

    if (swap_endian64(test_num64) != test_num64_swapped) {
        printf("[INFO] Failed to swap endianness for 64bit integer: %lu -> %lu; supposed to get %lu\n",
            test_num64, swap_endian64(test_num64), test_num64_swapped
        );
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int main() {
    // rng
    printf("[INFO] Testing rng...\n");
    if (test_rng() == EXIT_FAILURE) {
        printf("[INFO] RNG test failed\n\n");
    } else {
        printf("[INFO] RNG test passed\n\n");
    }

    // img
    printf("[INFO] Testing img...\n");
    if (test_img() == EXIT_FAILURE) {
        printf("[INFO] IMG test failed\n\n");
    } else {
        printf("[INFO] IMG test passed\n\n");
    }

    // endianness
    printf("[INFO] Testing endian...\n");
    if (test_endian() == EXIT_FAILURE) {
        printf("[INFO] Endian test failed\n\n");
    } else {
        printf("[INFO] Endian test passed\n\n");
    }

    return EXIT_SUCCESS;
}