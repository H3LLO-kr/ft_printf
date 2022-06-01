/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:44:32 by chanhapa          #+#    #+#             */
/*   Updated: 2022/06/01 22:52:17 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	_write_u_r(unsigned int n)
{
	char	c;

	if (n / 10 == 0)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		_write_u_r(n / 10);
		c = n % 10 + '0';
		write(1, &c, 1);
	}
}

void	_print_u(unsigned int n)
{
	_write_u_r(n);
}
