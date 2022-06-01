/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_xX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:52:28 by chanhapa          #+#    #+#             */
/*   Updated: 2022/06/02 00:59:37 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_write_hex_l_r(unsigned int nbr)
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
		ret = _write_hex_l_r(nbr / 16);
		if (nbr % 16 < 10)
			c = nbr % 16 + '0';
		else
			c = nbr % 16 + 'a' - 10;
		write(1, &c, 1);
		return (ret + 1);
	}
}

int	_write_hex_h_r(unsigned int nbr)
{
	char	c;
	int		ret;

	if (nbr / 16 == 0)
	{
		if (nbr % 16 < 10)
			c = nbr + '0';
		else
			c = nbr + 'A' - 10;
		write(1, &c, 1);
		return (1);
	}
	else
	{
		ret = _write_hex_h_r(nbr / 16);
		if (nbr % 16 < 10)
			c = nbr % 16 + '0';
		else
			c = nbr % 16 + 'A' - 10;
		write(1, &c, 1);
		return (ret + 1);
	}
}

int	_print_xX(int n, int lowhigh)
{
	unsigned int	nbr;
	int				ret;

	ret = 0;
	nbr = n;
	if (lowhigh == 0)
		ret += _write_hex_l_r(nbr);
	else
		ret += _write_hex_h_r(nbr);
	return (ret);
}
