/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:37:38 by chanhapa          #+#    #+#             */
/*   Updated: 2022/05/21 14:42:27 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *strbuf, ...)
{
	va_list	ap;
	int		index;

	index = 0;
	va_start(ap, 10);
	while (strbuf[index])
	{
		if (strbuf[index] == '%')
		{
			continue;
		}
		else
		{
			ft_putchar_fd(strbuf[index], 1);
		}
	}
}
