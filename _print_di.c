/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:49:33 by chanhapa          #+#    #+#             */
/*   Updated: 2022/06/01 22:51:39 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_write_r(long nbr)
{
	char	c;

	if (nbr / 10 == 0)
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
	else
	{
		_write_r(nbr / 10);
		c = nbr % 10 + '0';
		write(1, &c, 1);
	}
}

void	_print_di(int n)
{
	long	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	_write_r(nbr);
}
