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

#include "../src/rng/rng.h"
#include "../src/img/ppm.h"
#include "../src/endian/endian.h"
#include "../src/fs/fs.h"
#include "../src/bits/bits.h"
#include "../src/math/vector.h"

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
        printf("[ERROR] Failed to swap endianness for 16bit integer: %u -> %u; supposed to get %u\n",
            test_num16, swap_endian16(test_num16), test_num16_swapped
        );
        return EXIT_FAILURE;
    }

    // 00000000 01101110 11101110 11110101
    const uint32_t test_num32 = 7270133;
    // 11110101 11101110 01101110 00000000
    const uint32_t test_num32_swapped = 4126043648;

    if ((swap_endian32(test_num32)) != test_num32_swapped) {
        printf("[ERROR] Failed to swap endianness for 32bit integer: %u -> %u; supposed to get %u\n",
            test_num32, swap_endian32(test_num32), test_num32_swapped
        );
        return EXIT_FAILURE;
    }

    // 00000000 00000000 11010110 00000000 10010111 10001111 00000000 00000000
    const uint64_t test_num64 = 235298031075328;

    // 11110101 10011110 10001111 00000000 00000000 00000000 00000000 00000000
    const uint64_t test_num64_swapped = 157878716858368;

    if (swap_endian64(test_num64) != test_num64_swapped) {
        printf("[ERROR] Failed to swap endianness for 64bit integer: %lu -> %lu; supposed to get %lu\n",
            test_num64, swap_endian64(test_num64), test_num64_swapped
        );
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int test_fs() {
    if (file_size("test_img512x512.ppm") == UINT64_MAX) {
        printf("[ERROR] Failed to determine file size of test ppm image\n");
        return EXIT_FAILURE;
    }

    if (copy_file("test_img512x512.ppm", "copied_ppm_file.ppm") == -1) {
        printf("[ERROR] Failed to copy test ppm image\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int test_bits() {
    // 11001000
    uint8_t test_byte = 200;
    // 11001001
    const uint8_t test_byte_first_bit_set = 201;
    // 11001000
    const uint8_t test_byte_first_bit_unset = 200;


    if (get_byte_bit(test_byte, 1) != 0) {
        printf(
            "[ERROR] Failed to correctly determine the first bit in %d: supposed to get %d but got %d instead\n",
             test_byte, 
             get_byte_bit(test_byte, 1),
             0);
        return EXIT_FAILURE;
    }

    set_byte_bit(&test_byte, 1);
    if (test_byte != test_byte_first_bit_set) {
        printf("[ERROR] Failed to set the first bit to 1 in %d\n", test_byte);
        return EXIT_FAILURE;
    }

    unset_byte_bit(&test_byte, 1);
    if (test_byte != test_byte_first_bit_unset) {
        printf("[ERROR] Failed to unset the first bit in %d\n", test_byte);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int test_vector() {
    const long double threshold = 0.01;

    vec2 vec2d = {2, 3};
    vec2 vec2d_other = {3, 2};
    long long int multiplied;

    if (fabsl(vec2_len(vec2d) - 3.606f) > threshold) {
        printf("[ERROR] Vector length calculation is wrong: expeted to be %f (+-%Lf); got %Lf\n",
            3.606f, threshold, vec2_len(vec2d)
        );
        return EXIT_FAILURE;
    }

    multiplied = vec2_multiply_scalar(vec2d, vec2d_other);
    if (multiplied != (vec2d.x*vec2d_other.x + vec2d.y*vec2d_other.y)) {
        printf("[ERROR] Vector scalar multiplication is wrong\n");
        return EXIT_FAILURE;
    }

    vec2d = (vec2){3, 4};
    vec2d_other = (vec2){4, 3};
    if (fabsl(vec2_angle(vec2d, vec2d_other) - 0.96f) > threshold) {
        printf("[ERROR] Failed to calculate angle between 2 vectors: expected to be %f (+-%Lf); got %Lf\n",
            0.96f, threshold, vec2_angle(vec2d, vec2d_other)
        );
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int test_math() {
    if (test_vector() == EXIT_FAILURE) {
        printf("[ERROR] Vector test failed\n");
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

    // fs
    printf("[INFO] Testing fs...\n");
    if (test_fs() == EXIT_FAILURE) {
        printf("[INFO] FS test failed\n\n");
    } else {
        printf("[INFO] FS test passed\n\n");
    }

    // bits
    printf("[INFO] Testing bits...\n");
    if (test_bits() == EXIT_FAILURE) {
        printf("[INFO] Bits test failed\n\n");
    } else {
        printf("[INFO] Bits test passed\n\n");
    }

    // math
    printf("[INFO] Testing math...\n");
    if (test_math() == EXIT_FAILURE) {
        printf("[INFO] Math test failed\n\n");
    } else {
        printf("[INFO] Math test passed\n\n");
    }

    return EXIT_SUCCESS;
}