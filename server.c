/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:37:26 by dinoguei          #+#    #+#             */
/*   Updated: 2023/01/16 15:12:02 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int signalinfo)
{
	static unsigned char	bit;
	static unsigned char	bin;
	static int				i = 0;

	if (signalinfo == SIGUSR1)
	{
		bin = 1;
		bit = bit | (bin << i);
		i++;
	}
	else if (signalinfo == SIGUSR2)
	{
		bin = 0;
		bit = bit | (bin << i);
		i++;
	}
	if (i == 8)
	{
		ft_printf("%c", (char)bit);
		bit = 0;
		i = 0;
	}
}

void	signaltreatment(void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
}

int	main(void)
{
	ft_printf("The servers PID is: %d\n", getpid());
	signaltreatment();
	while (1)
		pause();
}
