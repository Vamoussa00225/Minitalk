/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:21:30 by vkanate           #+#    #+#             */
/*   Updated: 2021/12/10 22:12:47 by vkanate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *chaine, ...);
void	ft_putnbr(long int n, int *len);
void	ft_putunbr(unsigned int n, int *len);
void	ft_puthexnbr(unsigned int n, int *len, char type);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);

#endif
