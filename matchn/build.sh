#!/bin/sh


echo building ex00
gcc -Wall -Wextra -Werror stupidity.c ex00/*.c -o ex00/a.out

echo building ex01
gcc -Wall -Wextra -Werror stupidity.c ex01/*.c -o ex01/a.out
