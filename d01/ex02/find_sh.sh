# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    find_sh.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmoiseye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 09:42:53 by nmoiseye          #+#    #+#              #
#    Updated: 2017/01/11 18:51:34 by nmoiseye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

find . -name '*.sh' -type f | rev | cut -d '/' -f 1 | rev | sed 's/\.sh$//'

