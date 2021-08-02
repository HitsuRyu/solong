/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:02:32 by cdahlia           #+#    #+#             */
/*   Updated: 2021/07/30 19:02:33 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		len;

	len = 0;
	tmp = lst;
	if (lst == NULL)
		return (0);
	while (tmp->next != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len + 1);
}
