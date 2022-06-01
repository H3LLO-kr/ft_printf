/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_xX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:52:28 by chanhapa          #+#    #+#             */
/*   Updated: 2022/06/01 22:54:54 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_write_hex_l_r(long nbr)
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
		_write_hex_l_r(nbr / 16);
		if (nbr % 16 < 10)
			c = nbr % 16 + '0';
		else
			c = nbr % 16 + 'a' - 10;
		write(1, &c, 1);
	}
}

void	_write_hex_h_r(long nbr)
{
	char	c;

	if (nbr / 16 == 0)
	{
		if (nbr % 16 < 10)
			c = nbr + '0';
		else
			c = nbr + 'A' - 10;
		write(1, &c, 1);
	}
	else
	{
		_write_hex_h_r(nbr / 16);
		if (nbr % 16 < 10)
			c = nbr % 16 + '0';
		else
			c = nbr % 16 + 'A';
		write(1, &c, 1);
	}
}

void	_print_xX(int n, int lowhigh)
{
		long	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (lowhigh == 0)
		_write_hex_l_r(nbr);
	else
		_write_hex_h_r(nbr);
}
