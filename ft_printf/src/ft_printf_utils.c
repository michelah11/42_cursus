/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:44:08 by mabou-ha          #+#    #+#             */
/*   Updated: 2024/06/22 03:38:18 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putchar_pf(int c)
{
	ft_putchar_fd((char)c, 1);
	return (1);
}

int	ft_putstr_pf(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr_pf("(null)"));
	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_pf(int num)
{
	char	*str;
	int		len;

	str = ft_itoa(num);
	len = ft_putstr_pf(str);
	return (len);
}
