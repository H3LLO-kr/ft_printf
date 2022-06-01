/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 23:02:56 by chanhapa          #+#    #+#             */
/*   Updated: 2022/06/02 00:18:29 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	int		i;

	i = 0;
	chr = c;
	while (s[i] != chr)
	{
		if (!s[i])
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}
