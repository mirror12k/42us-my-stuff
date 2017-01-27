/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_print.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoiseye <mirror12k@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:00:11 by nmoiseye          #+#    #+#             */
/*   Updated: 2017/01/26 13:02:21 by nmoiseye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_PRINT_H
# define FT_HEXDUMP_PRINT_H

void	print_hex(unsigned char c, int count);
void	print_addr(unsigned int addr, int enable_text);
void	print_data(char *data, int limit, int enable_break);
void	print_text(char *data, int limit);
void	print_buffer_line(int offset, char *buffer, int bytes, int enable_text);

#endif
