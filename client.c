/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:32:35 by vkanate           #+#    #+#             */
/*   Updated: 2022/01/14 14:55:11 by vkanate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(char *message, int pid, int len)
{
	int	shift;
	int	i;

	shift = -1;
	i = 0;
	while (i <= len)
	{
		while (++shift < 8)
		{
			if (message[i] & (0x80 >> shift))
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			else if (kill(pid, SIGUSR1) == -1)
				exit (1);
			usleep(500);
		}
		i++;
		shift = -1;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		len;

	if (argc != 3)
	{
		ft_printf("invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(argv[2]);
	pid = ft_atoi(argv[1]);
	send_signals(argv[2], pid, len);
	return (0);
}
