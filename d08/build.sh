#!/bin/sh


echo building ex05
gcc -Wall -Wextra -Werror stupidity.c ex05/*.c -o ex05/a.out

echo building ex06
gcc -Wall -Wextra -Werror stupidity.c ex06/*.c -o ex06/a.out
