/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:37:53 by chanhapa          #+#    #+#             */
/*   Updated: 2022/06/02 00:44:02 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

//_print functions
int		_print_c(char c);
int		_print_di(int n);
int		_print_p(long n);
int		_print_s(char *s);
int		_print_u(unsigned int n);
int		_print_xX(int n, int lowhigh);

//Libft
char	*ft_strchr(const char *s, int c);

//printf
int		ft_printf(const char *strbuf, ...);
int		_count_argu(const char *strbuf);
int		_printf_extra(va_list *ap, char c);

#endif
