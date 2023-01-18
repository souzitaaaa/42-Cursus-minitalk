/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:37:37 by dinoguei          #+#    #+#             */
/*   Updated: 2023/01/16 15:38:46 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*g_out = 0;

static void	handler(int signalinfo, siginfo_t *info, void *prev_act)
{
	static unsigned char	bit;
	static unsigned char	bin;
	static int				i = 0;

	(void)prev_act;
	bin = (signalinfo == SIGUSR1);
	bit = bit | (bin << i);
	i++;
	if (i == 8)
	{
		g_out = ft_strjoinserver(g_out, bit);
		if (bit == '\0')
		{
			ft_printf("%s", g_out);
			kill(info->si_pid, SIGUSR1);
			free (g_out);
			g_out = 0;
		}
		bit = 0;
		i = 0;
	}
}

void	signaltreatment(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = &handler;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
}

int	main(void)
{
	ft_printf("The servers PID is: %d\n", getpid());
	signaltreatment();
	while (1)
		pause();
}
