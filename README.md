# AUXILIB
## A collection of various drop-in helper functions; AKA auxiliary C/С++ library

# Build
`make lib` or, if you don't have make or don't use gcc - translate the "lib" recipe into what works best for you, ie:
`gcc -Wall -Werror -O2 -shared src/*/*.c -o auxilib`

# Use
Either
- Compile the library as a whole separately and use that
or
- Copy file(s) with needed functionality to your project

# License
Currently auxilib uses MIT license.
You're free to do anything you want, just don't forget to include a notice !