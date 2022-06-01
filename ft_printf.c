/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:37:38 by chanhapa          #+#    #+#             */
/*   Updated: 2022/06/01 17:31:50 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *strbuf, ...)
{
	va_list	ap;
	int		index;

	index = 0;
	va_start(ap, strbuf);
	while (strbuf[index])
	{
		if (strbuf[index] == '%')
		{
			_printf_extra(ap, strbuf[index + 1]);
			index++;
		}
		else
		{
			ft_putchar_fd(strbuf[index], 1);
			index++;
		}
	}
	va_end(ap);
	return (0);
}

void	_printf_extra(va_list ap, char c)
{
	
}

int	_count_argu(const char *strbuf)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (strbuf[i])
	{
		if (strbuf[i] == '%')
			count++;
		i++;
	}
	return (count);
}
