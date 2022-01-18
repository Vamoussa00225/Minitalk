/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:07:50 by vkanate           #+#    #+#             */
/*   Updated: 2022/01/14 13:57:15 by vkanate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(char *message, int pid, int len)
{
	int	i;
	int	shift;

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

void	serveur_ack(int i)
{
	if (i == SIGUSR1)
		write(1, "Message recu avec succes\n", 25);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	signal(SIGUSR1, serveur_ack);
	if (argc != 3)
	{
		ft_printf("invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	i = ft_strlen(argv[2]);
	pid = ft_atoi(argv[1]);
	send_signals(argv[2], pid, i);
	return (0);
}
