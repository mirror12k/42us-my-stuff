# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    r_dwssap.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmoiseye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 11:43:59 by nmoiseye          #+#    #+#              #
#    Updated: 2017/01/10 11:44:15 by nmoiseye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cat /etc/passwd | grep -v -E '^\s*#' | awk 'NR % 2 == 0' | cut -d ':' -f 1 | rev | sort -r | head -n $FT_LINE2 | tail -n $(($FT_LINE2-$FT_LINE1+1)) | perl -pe 's/\n/, /' | perl -pe 's/, $/./'

