/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:43:08 by chanhapa          #+#    #+#             */
/*   Updated: 2022/06/02 00:53:06 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_write_hex_p_r(unsigned long nbr)
{
	char	c;
	int		ret;

	if (nbr / 16 == 0)
	{
		if (nbr % 16 < 10)
			c = nbr + '0';
		else
			c = nbr + 'a' - 10;
		write(1, &c, 1);
		return (1);
	}
	else
	{
		ret = _write_hex_p_r(nbr / 16);
		if (nbr % 16 < 10)
			c = nbr % 16 + '0';
		else
			c = nbr % 16 + 'a' - 10;
		write(1, &c, 1);
		return (ret + 1);
	}
}

int	_print_p(long n)
{
	unsigned long	nbr;
	int				ret;

	ret = 2;
	nbr = n;
	write(1, "0x", 2);
	ret += _write_hex_p_r(nbr);
	return (ret);
}
