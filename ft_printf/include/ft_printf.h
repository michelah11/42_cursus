/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:44:45 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/22 04:03:14 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define LOWER_CASE_HEX "0123456789abcdef"
# define UPPER_CASE_HEX "0123456789ABCDEF"

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_formatter(char c, va_list ap);
int	ft_putchar_pf(int c);
int	ft_putstr_pf(char *str);
int	ft_putptr_pf(size_t nbr);
int	ft_putnbr_pf(int num);
int	ft_putuint_pf(unsigned int num);
int	ft_puthex_pf(unsigned int num, char *base);

# ifndef NULL_POINTER
#  define NULL_POINTER "(nil)"
# endif

#endif
