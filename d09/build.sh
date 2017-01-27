#!/bin/sh

gcc -Wall -Wextra -Werror ex00/*.c -o ex00/main

echo building ex01
gcc -Wall -Wextra -Werror stupidity.c ex01/*.c -o ex01/a.out

echo building ex05
gcc -Wall -Wextra -Werror stupidity.c ex05/*.c -o ex05/a.out

echo building ex06
gcc -Wall -Wextra -Werror stupidity.c ex06/*.c -o ex06/a.out

echo building ex07
gcc -Wall -Wextra -Werror stupidity.c ex07/*.c -o ex07/a.out

echo building ex08
gcc -Wall -Wextra -Werror stupidity.c ex08/ft_spy.c -o ex08/a.out
