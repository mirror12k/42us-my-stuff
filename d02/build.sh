#!/bin/sh

echo compiling ex00
gcc -DSTUPIDITY -Wall -Wextra -Werror stupidity.c ex00/*.c -o ex00/a.out
echo compiling ex01
gcc -DSTUPIDITY -Wall -Wextra -Werror stupidity.c ex01/*.c -o ex01/a.out
echo compiling ex02
gcc -DSTUPIDITY -Wall -Wextra -Werror stupidity.c ex02/*.c -o ex02/a.out


echo building ex03
gcc -DSTUPIDITY -Wall -Wextra -Werror stupidity.c ex03/*.c -o ex03/a.out

echo building ex04
gcc -DSTUPIDITY -Wall -Wextra -Werror stupidity.c ex04/*.c -o ex04/a.out

echo building ex05
gcc -DSTUPIDITY -Wall -Wextra -Werror stupidity.c ex05/*.c -o ex05/a.out

echo building ex06
gcc -DSTUPIDITY -Wall -Wextra -Werror stupidity.c ex06/*.c -o ex06/a.out

echo building ex07
gcc -DSTUPIDITY -Wall -Wextra -Werror stupidity.c ex07/*.c -o ex07/a.out
