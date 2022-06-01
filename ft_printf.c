/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:37:38 by chanhapa          #+#    #+#             */
/*   Updated: 2022/06/02 00:17:51 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			_printf_extra(&ap, strbuf[index + 1]);
			index += 2;
		}
		else
		{
			_print_c(strbuf[index]);
			index++;
		}
	}
	va_end(ap);
	return (0);
}

void	_printf_extra(va_list* ap, char c)
{
	if (c == 'c')
		_print_c(va_arg(*ap, int));
	else if (c == 's')
		_print_s(va_arg(*ap, char*));
	else if (c == 'p')
		_print_p(va_arg(*ap, long));
	else if (ft_strchr("di", c))
		_print_di(va_arg(*ap, int));
	else if (c == 'u')
		_print_u(va_arg(*ap, unsigned int));
	else if (c == 'x')
		_print_xX(va_arg(*ap, int), 0);
	else if (c == 'X')
		_print_xX(va_arg(*ap, int), 1);
	else if (c == '%')
		write(1, "%", 1);
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
