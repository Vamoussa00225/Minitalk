/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 23:45:50 by vkanate           #+#    #+#             */
/*   Updated: 2021/12/10 22:13:12 by vkanate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		*len += 1;
		i++;
	}
	return ;
}

void	ft_putnbr(long int n, int *len)
{
	if (n < 0)
	{
		ft_putchar('-', len);
		n *= -1;
	}
	if (n <= 9 && n >= 0)
	{		
		ft_putchar((n % 10 + '0'), len);
		return ;
	}
	ft_putnbr((n / 10), len);
	ft_putchar((n % 10 + '0'), len);
}

void	ft_puthexnbr(unsigned int n, int *len, char type)
{
	char	*hex;
	int		i;

	if (type == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	i = -1;
	if (n <= 15 && n >= 0)
	{
		while (hex[++i] != '\0')
		{
			if (i == (n % 16))
				ft_putchar(hex[i], len);
		}
		return ;
	}
	ft_puthexnbr(n / 16, len, type);
	i = -1;
	while (hex[++i] != '\0')
	{
		if (i == (n % 16))
			ft_putchar(hex[i], len);
	}
}
