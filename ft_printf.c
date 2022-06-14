/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:37:38 by chanhapa          #+#    #+#             */
/*   Updated: 2022/06/14 16:28:18 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *strbuf, ...)
{
	va_list	ap;
	int		index;
	int		ret;

	index = 0;
	ret = 0;
	va_start(ap, strbuf);
	while (strbuf[index])
	{
		if (strbuf[index] == '%')
		{
			ret += _printf_extra(&ap, strbuf[index + 1]);
			index += 2;
		}
		else
		{
			ret += _print_c(strbuf[index]);
			index++;
		}
	}
	va_end(ap);
	return (ret);
}

int	_printf_extra(va_list *ap, char c)
{
	int	ret;

	ret = 0;
	if (c == 'c')
		ret = _print_c(va_arg(*ap, int));
	else if (c == 's')
		ret = _print_s(va_arg(*ap, char *));
	else if (c == 'p')
		ret = _print_p(va_arg(*ap, long));
	else if (ft_strchr("di", c))
		ret = _print_di(va_arg(*ap, int));
	else if (c == 'u')
		ret = _print_u(va_arg(*ap, unsigned int));
	else if (c == 'x')
		ret = _print_xux(va_arg(*ap, int), 0);
	else if (c == 'X')
		ret = _print_xux(va_arg(*ap, int), 1);
	else if (c == '%')
	{
		write(1, "%", 1);
		ret = 1;
	}
	return (ret);
}
