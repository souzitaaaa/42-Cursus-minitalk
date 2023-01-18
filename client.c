/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:21:23 by dinoguei          #+#    #+#             */
/*   Updated: 2023/01/16 15:37:04 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_server(int pid, char *str)
{
	int		i;
	int		bit;
	char	c;

	bit = 8;
	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		while (bit--)
		{
			if (c & 0b00000001)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			c >>= 1;
			usleep (60);
		}
		i++;
		bit = 8;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (ft_printf("[./client 12345 dinoguei]"));
	pid = ft_atoi(argv[1]);
	send_server(pid, argv[2]);
	return (0);
}
