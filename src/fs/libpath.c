/*
The MIT License (MIT)

Copyright © 2023 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// File path separator. '/' by default and '\\' for Windows and DOS 
const char PATH_SEPARATOR = 
#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__DOS__) || defined(__SYMBIAN32__)
    '\\';
#else
    '/';
#endif

/*
Clears allocated path from duplicate separators.
Reallocates memory if needed.
*/
void path_clean(char* path) {
    size_t path_len;
    size_t i;

    if (!path) {
        return;
    }

    path_len = strlen(path);
    if (path_len <= 1) {
        return;
    }

    // remove trailing separator if present
    if (path[path_len-1] == PATH_SEPARATOR) {
        path[path_len-1] = '\0';
        path_len--;
    }

    if (path_len <= 1) {
        return;
    }

    // get rid of duplicate separators
    i = 1;
    while (i < path_len) {
        if (path[i-1] == PATH_SEPARATOR && path[i] == PATH_SEPARATOR) {
            // move to the left
            for (size_t j = i; j < path_len-1; j++) {
                path[j] = path[j + 1];
            }
            path[path_len-1] = '\0';
            path_len--;
            i--;
        }
        i++;
    }

    path = realloc(path, sizeof(char) * path_len);
}

/*
Clears allocated path from duplicate separators
and returns allocated clean path.
Be sure to path_free() after use.
*/
char* path_clean_copy(const char* path) {
    char* clean_path = NULL;
    size_t path_len;
    
    if (!path) {
        return NULL;
    }
    path_len = strlen(path);
    
    clean_path = malloc(sizeof(char) * (path_len + 1));
    clean_path = memcpy(clean_path, path, sizeof(char) * (path_len + 1));
    path_clean(clean_path);
    
    return clean_path;
}

/*
Joins path parts together and allocates the resulting path.
Takes counter for the amount of path parts; path parts must be of char* type.
Calls path_clean on the appended parts.
Be sure to path_free() after use.
*/
char* path_join(unsigned int count, ...) {
    char* resulting_path = NULL;
    const char* part = NULL;
    unsigned long part_len = 0;
    unsigned long current_len = 0;
    va_list list;
    unsigned int i = 0;

    va_start(list, count);
    while (i < count) {
        part = va_arg(list, const char*);
        part_len = strlen(part);
        resulting_path = realloc(resulting_path, current_len + part_len + 1);
        for (unsigned long i = current_len; i < current_len+part_len; i++) {
            resulting_path[i] = part[i-current_len];
        }
        resulting_path[current_len+part_len] = PATH_SEPARATOR;
        current_len += part_len + 1;
        i++;
    }
    resulting_path[current_len] = '\0';
    va_end(list);

    path_clean(resulting_path);
    
    return resulting_path;
}

// Frees path and sets pointer to NULL
void path_free(char** path) {
    free(*path);
    *path = NULL;
}

/*
Creates a new path pointing to the parent.
Be sure to path_free() on the base as well after use.
*/
char* path_parent_copy(const char* path) {
    if (!path) {
        return NULL;
    }

    char* parent_path = NULL;
    char* clean_path = NULL;
    size_t path_len;
    size_t last_separator_index = 0;

    clean_path = path_clean_copy(path);
    if (!clean_path) {
        return NULL;
    }
    path_len = strlen(clean_path);

    if (path_len <= 1) {
        return NULL;
    }

    // find the last separator index in clean path
    for (size_t i = 0; i < path_len; i++) {
        if (clean_path[i] == PATH_SEPARATOR) {
            last_separator_index = i;
        }
    }

    if (last_separator_index == 0) {
        return clean_path;
    }

    // allocate memory to hold up to last separator bytes
    parent_path = malloc(sizeof(char) * last_separator_index);
    if (!parent_path) {
        return NULL;
    }

    // copy over
    memcpy(parent_path, clean_path, sizeof(char) * last_separator_index);
    parent_path[last_separator_index] = '\0';

    // free temporary cleaned path
    path_free(&clean_path);

    return parent_path;
}

/*
Shrinks given path so that it points to the parent.
Reallocates memory.
*/
void path_parent(char* path) {
    if (!path) {
        return;
    }
    
    path_clean(path);

    size_t path_len = strlen(path);
    size_t last_separator_index = 0;

    // find the last separator index
    for (size_t i = 0; i < path_len; i++) {
        if (path[i] == PATH_SEPARATOR) {
            last_separator_index = i;
        }
    }

    if (last_separator_index == 0) {
        return;
    }

    path = realloc(path, sizeof(char) * last_separator_index);
    path[last_separator_index] = '\0';
}

/*
Swaps Windows' path separators (\) in given path with
POSIX path separators (/) if compiled for POSIX systems
and the other way around. Calls path_clean on the resulting
path 
*/
void path_to_native_separators(char* path) {
    if (!path) {
        return;
    }

    size_t path_len = strlen(path);

    for (size_t i = 0; i < path_len; i++) {
        if (path[i] == '\\' || path[i] == '/') {
            path[i] = PATH_SEPARATOR;
        }
    }

    path_clean(path);
}