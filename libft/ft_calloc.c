/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:01:35 by cdahlia           #+#    #+#             */
/*   Updated: 2021/07/30 19:01:35 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = NULL;
	i = 0;
	ptr = (char *)malloc(count * size);
	if (!ptr)
	{
		return (NULL);
	}
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
