/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:21:02 by vkanate           #+#    #+#             */
/*   Updated: 2022/01/13 19:18:07 by vkanate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putvoid(void *nb, int *len)
{
	char				*hex;
	int					i;
	unsigned long int	n;

	n = (unsigned long int)nb;
	hex = "0123456789abcdef";
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
	ft_putvoid((void *)(n / 16), len);
	i = -1;
	while (hex[++i] != '\0')
	{
		if (i == (n % 16))
			ft_putchar(hex[i], len);
	}
}

void	ft_print(const char *chaine, int *len, va_list ap, int *i)
{
	if (chaine[*i] == '%')
		ft_putstr("%", len);
	else if (chaine[*i] == 'i' || chaine[*i] == 'd')
		ft_putnbr(va_arg(ap, int), len);
	else if (chaine[*i] == 'u')
		ft_putnbr((unsigned int)va_arg(ap, unsigned int), len);
	else if (chaine[*i] == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (chaine[*i] == 'c')
		ft_putchar((char)va_arg(ap, int), len);
	else if (chaine[*i] == 'x')
		ft_puthexnbr(va_arg(ap, int), len, 'x');
	else if (chaine[*i] == 'X')
		ft_puthexnbr(va_arg(ap, int), len, 'X');
	else if (chaine[*i] == 'p')
	{
		ft_putstr("0x", len);
		ft_putvoid(va_arg(ap, void *), len);
	}
}

int	ft_printf(const char *chaine, ...)
{
	int			len;
	int			i;
	va_list		ap;

	len = 0;
	i = -1;
	va_start(ap, chaine);
	while (chaine[++i] != '\0')
	{
		if (chaine[i] == '%')
		{
			i++;
			ft_print(chaine, &len, ap, &i);
		}
		else
			ft_putchar(chaine[i], &len);
	}
	va_end(ap);
	return (len);
}
