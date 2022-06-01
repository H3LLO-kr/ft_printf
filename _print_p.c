/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:43:08 by chanhapa          #+#    #+#             */
/*   Updated: 2022/06/02 00:20:48 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_write_hex_p_r(long long nbr)
{
	char	c;

	if (nbr / 16 == 0)
	{
		if (nbr % 16 < 10)
			c = nbr + '0';
		else
			c = nbr + 'a' - 10;
		write(1, &c, 1);
	}
	else
	{
		_write_hex_p_r(nbr / 16);
		if (nbr % 16 < 10)
			c = nbr % 16 + '0';
		else
			c = nbr % 16 + 'a' - 10;
		write(1, &c, 1);
	}
}

void	_print_p(long n)
{
	long long	nbr;

	nbr = n;
	write(1, "0x", 2);
	_write_hex_p_r(nbr);
}
