#!/bin/sh

gcc -Wall -Wextra -Werror stupidity.c ex01/ft_print_program_name.c -o ex01/main

echo building ex02
gcc -Wall -Wextra -Werror stupidity.c ex02/ft_print_params.c -o ex02/a.out

echo building ex03
gcc -Wall -Wextra -Werror stupidity.c ex03/ft_rev_params.c -o ex03/a.out

echo building ex04
gcc -Wall -Wextra -Werror stupidity.c ex04/ft_sort_params.c -o ex04/a.out
