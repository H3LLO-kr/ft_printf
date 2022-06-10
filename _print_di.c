/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:49:33 by chanhapa          #+#    #+#             */
/*   Updated: 2022/06/10 11:41:11 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_write_r(long nbr)
{
	char	c;
	int		ret;

	if (nbr / 10 == 0)
	{
		c = nbr + '0';
		write(1, &c, 1);
		return (1);
	}
	else
	{
		ret = _write_r(nbr / 10);
		c = nbr % 10 + '0';
		write(1, &c, 1);
		return (ret + 1);
	}
}

int	_print_di(int n)
{
	long	nbr;
	int		ret;

	nbr = n;
	ret = 0;
	if (n < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
		ret++;
	}
	ret += _write_r(nbr);
	return (ret);
}
