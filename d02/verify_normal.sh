#!/bin/sh

norminette -R CheckForbiddenSourceHeader ex00/ft_print_alphabet.c
norminette -R CheckForbiddenSourceHeader ex01/ft_print_reverse_alphabet.c
norminette -R CheckForbiddenSourceHeader ex02/ft_print_numbers.c


norminette -R CheckForbiddenSourceHeader ex03/ft_is_negative.c

norminette -R CheckForbiddenSourceHeader ex04/ft_print_comb.c

norminette -R CheckForbiddenSourceHeader ex05/ft_print_comb2.c

norminette -R CheckForbiddenSourceHeader ex06/ft_putnbr.c

norminette -R CheckForbiddenSourceHeader ex07/ft_print_combn.c
