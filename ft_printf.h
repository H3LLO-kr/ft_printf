/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:37:53 by chanhapa          #+#    #+#             */
/*   Updated: 2022/06/02 00:17:39 by chanhapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

//_print functions
void	_print_c(char c);
void	_print_di(int n);
void	_print_p(long n);
void	_print_s(char *s);
void	_print_u(unsigned int n);
void	_print_xX(int n, int lowhigh);

//Libft
char	*ft_strchr(const char *s, int c);

//printf
int		ft_printf(const char *strbuf, ...);
int		_count_argu(const char *strbuf);
void    _printf_extra(va_list* ap, char c);

#endif
