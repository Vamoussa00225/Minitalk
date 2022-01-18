/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkanate <vkanate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:11:10 by vkanate           #+#    #+#             */
/*   Updated: 2022/01/14 14:56:01 by vkanate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

void	reset(char *c, int *n, int pid)
{
	*c = 0xFF;
	*n = 0;
	g_pid = pid;
}

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bits = 0;

	(void)context;
	if (g_pid != info->si_pid)
		reset(&c, &bits, info->si_pid);
	if (signum == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c |= 0x80 >> bits;
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		if (!c)
		{
			kill(g_pid, SIGUSR1);
			write(1, "\n", 1);
		}
		bits = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler_sigusr;
	sigemptyset(&sa.sa_mask);
	ft_printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
