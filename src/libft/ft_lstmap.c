/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:02:29 by cdahlia           #+#    #+#             */
/*   Updated: 2021/07/30 19:02:29 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*head;

	if (lst == NULL)
		return (NULL);
	copy = ft_lstnew(f(lst->content));
	if (copy == NULL)
		return (NULL);
	head = copy;
	lst = lst->next;
	while (lst != NULL)
	{
		copy->next = ft_lstnew(f(lst->content));
		if (copy->next == NULL)
		{
			ft_lstclear(&copy, del);
			return (NULL);
		}
		copy = copy->next;
		lst = lst->next;
	}
	copy->next = NULL;
	return (head);
}
