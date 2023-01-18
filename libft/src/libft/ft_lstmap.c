/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:18:22 by dinoguei          #+#    #+#             */
/*   Updated: 2022/11/21 16:43:16 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*no_element(t_list *lst, t_list *new_element, void (*del)(void *))
{
	if (!new_element)
	{
		ft_lstclear(&lst, (*del));
		return (NULL);
	}
	return (new_element);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_element;

	new_lst = NULL;
	if (!(*f) || !*del)
		return (NULL);
	new_element = NULL;
	while (lst)
	{
		new_element = ft_lstnew(f(lst -> content));
		if (!new_element)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_lst, del);
			break ;
		}
		ft_lstadd_back(&new_lst, new_element);
		lst = lst -> next;
	}
	return (new_lst);
}
