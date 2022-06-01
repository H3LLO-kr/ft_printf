/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:33:35 by chanhapa          #+#    #+#             */
/*   Updated: 2022/06/01 14:56:20 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	_write_r(long nbr, int fd)
{
	char	c;

	if (nbr / 10 == 0)
	{
		c = nbr + '0';
		write(fd, &c, 1);
	}
	else
	{
		_write_r(nbr / 10, fd);
		c = nbr % 10 + '0';
		write(fd, &c, 1);
	}
}

void	_write_hex_r(long nbr, int fd)
{
	char	c;

	if (nbr / 16 == 0)
	{
		if (nbr % 16 < 10)
			c = nbr + '0';
		else
			c = nbr + 'A';
		write(fd, &c, 1);
	}
	else
	{
		_write_hex_r(nbr / 16, fd);
		if (nbr % 16 < 10)
			c = nbr % 16 + '0';
		else
			c = nbr % 16 + 'A';
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int base, int fd)
{
	long	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		write(fd, "-", 1);
	}
	if (base == 10)
		_write_r(nbr, fd);
	else if (base == 16)
		_write_hex_r(nbr, fd);
	else
		return ;
}
