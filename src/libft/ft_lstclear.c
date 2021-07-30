/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:02:21 by cdahlia           #+#    #+#             */
/*   Updated: 2021/07/30 19:02:21 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*saved;

	tmp = *lst;
	while (tmp != NULL)
	{
		saved = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = saved;
	}
	*lst = NULL;
}
