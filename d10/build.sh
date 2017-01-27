#!/bin/sh


echo building ex01
gcc -Wall -Wextra -Werror stupidity.c ex01/*.c -o ex01/a.out

echo building ex02
gcc -Wall -Wextra -Werror stupidity.c ex02/*.c -o ex02/a.out

echo building ex03
gcc -Wall -Wextra -Werror stupidity.c ex03/*.c -o ex03/a.out

echo building ex04
gcc -Wall -Wextra -Werror stupidity.c ex04/*.c -o ex04/a.out

echo building ex05
gcc -Wall -Wextra -Werror stupidity.c ex05/*.c -o ex05/a.out

echo building ex06
gcc -Wall -Wextra -Werror stupidity.c ex06/*.c -o ex06/a.out

echo building ex07
gcc -Wall -Wextra -Werror stupidity.c ex07/*.c -o ex07/a.out

echo building ex08
gcc -Wall -Wextra -Werror stupidity.c ex08/*.c -o ex08/a.out
