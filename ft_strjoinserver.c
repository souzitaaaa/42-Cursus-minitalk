/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinserver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:06:49 by dinoguei          #+#    #+#             */
/*   Updated: 2023/01/16 15:10:54 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*ft_strjoinserver(unsigned char *str, unsigned char c)
{
	int				counter;
	int				lens;
	unsigned char	*temp;

	lens = 0;
	counter = 0;
	if (str)
		lens = ft_strlen((char *)str);
	temp = malloc(sizeof(char) * (lens + 2));
	if (str)
	{
		while (str[counter] != '\0')
		{
			temp[counter] = str[counter];
			counter++;
		}
	}
	temp[counter] = c;
	temp[counter + 1] = '\0';
	if (str)
		free(str);
	return (temp);
}
