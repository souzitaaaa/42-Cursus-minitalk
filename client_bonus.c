/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:37:42 by dinoguei          #+#    #+#             */
/*   Updated: 2023/01/16 15:42:54 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_server(int pid, char *str)
{
	int		i;
	int		bit;
	char	c;
	int		lens;

	bit = 8;
	i = 0;
	lens = ft_strlen(str);
	while (i <= lens)
	{
		c = str[i];
		while (bit--)
		{
			if (c & 0b00000001)
				kill (pid, SIGUSR1);
			else
				kill (pid, SIGUSR2);
			c >>= 1;
			usleep (60);
		}
		i++;
		bit = 8;
	}
}

static void	handler(int signalinfo)
{
	if (signalinfo == SIGUSR1)
		ft_printf ("Message Received\n");
}

void	signaltreatment(void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (ft_printf("[./client 12345 dinoguei]"));
	pid = ft_atoi(argv[1]);
	signaltreatment();
	send_server(pid, argv[2]);
	return (0);
}
