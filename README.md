# AUXILIB
## A collection of various drop-in helper functions; AKA auxiliary C/С++ library

# Build
`make lib` or, if you don't have make or don't use gcc - translate the "lib" recipe into what works best for you, ie:
`gcc -Wall -Werror -O2 -shared src/*/*.c -o auxilib`

# Use
Either

- Build the library as a whole separately and use that

or

- Copy header(s) with implementation file(s) with needed functionality to your project

or

- Copy code from each implementation file of your choosing to your code; it does not cross-depends on other auxilib header files and is self-standing

# License
Currently auxilib uses MIT license.

You're free to do anything you want, just don't forget to include a notice !