/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:34:38 by jboustan          #+#    #+#             */
/*   Updated: 2024/06/29 22:31:07 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	process_format_specifier(char next, va_list args);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnumbr(int nb);
int	ft_putunumbr(unsigned int number);
int	ft_putaddress(void *ptr);
int	ft_puthexadecimal(unsigned int number, char *base);

#endif