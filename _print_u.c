/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _print_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:44:32 by chanhapa          #+#    #+#             */
/*   Updated: 2022/06/02 00:53:59 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_write_u_r(unsigned int n)
{
	char	c;
	int		ret;

	if (n / 10 == 0)
	{
		c = n + '0';
		write(1, &c, 1);
		return (1);
	}
	else
	{
		ret = _write_u_r(n / 10);
		c = n % 10 + '0';
		write(1, &c, 1);
		return (ret + 1);
	}
}

int	_print_u(unsigned int n)
{
	return (_write_u_r(n));
}
