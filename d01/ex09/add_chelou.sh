# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    add_chelou.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmoiseye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 12:43:17 by nmoiseye          #+#    #+#              #
#    Updated: 2017/01/10 13:39:28 by nmoiseye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# export FT_NBR1=\\\'?\"\\\"\'\\
# export FT_NBR1=\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"\!\\\"\\\"
# export FT_NBR1=\"\"!\"\"!\"\"!\"\"!\"\"
# export FT_NBR1=\"\"!\"\"!\"\"!\"\"!\"\"
# echo $FT_NBR1 | tr \'\\\\\"?\! 01234

# export FT_NBR2=rcrdmddd
# export FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo
# export FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo
# echo $FT_NBR2 | tr mrdoc 01234

# N1=$(echo $FT_NBR1 | tr \'\\\\\"?\! 01234)
# N2=$(echo $FT_NBR2 | tr mrdoc 01234)
N1=$(echo $FT_NBR1 | tr \'\\\\\"?\! 01234)
N2=$(echo $FT_NBR2 | tr mrdoc 01234)

# debugging stuff
# echo "$FT_NBR1 + $FT_NBR2"
# echo "$N1 + $N2"

echo "ibase=5; obase=D; $N1 + $N2" | bc | tr '0123456789ABC' 'gtaio luSnemf'
# gtaio luSnemf
# 0123456789abc

