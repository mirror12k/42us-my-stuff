# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmoiseye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 09:32:29 by nmoiseye          #+#    #+#              #
#    Updated: 2017/01/23 16:11:31 by nmoiseye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: build

build:
	gcc -Wall -Wextra -Werror -Iincludes -c srcs/*.c
	ar rc libft.a *.o

clean:
	rm -f *.o

fclean: clean
	rm -f libft.a

re: fclean all

