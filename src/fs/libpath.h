/*
The MIT License (MIT)

Copyright © 2023 Kasyanov Nikolay Alexeyevich (Unbewohnte)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/*
Clears allocated path from duplicate separators.
Reallocates memory if needed.
*/
void path_clean(char* path);

/*
Clears allocated path from duplicate separators
and returns allocated clean path.
Be sure to path_free() after use.
*/
char* path_clean_copy(const char* path);

/*
Joins path parts together and allocates the resulting path.
Takes counter for the amount of path parts; path parts must be of char* type.
Calls path_clean on the appended parts.
Be sure to path_free() after use.
*/  
char* path_join(unsigned int count, ...);

// Frees path and sets pointer to NULL
void path_free(char** path);

/*
Creates a new path pointing to the parent.
Be sure to path_free() on the base as well after use.
*/
char* path_parent_copy(const char* path);

/*
Shrinks given path so that it points to the parent.
Reallocates memory.
*/
void path_parent(char* path);

/*
Swaps Windows' path separators (\) in given path with
POSIX path separators (/) if compiled for POSIX systems
and the other way around. Calls path_clean on the resulting
path 
*/
void path_to_native_separators(char* path);