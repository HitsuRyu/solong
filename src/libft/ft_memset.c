/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:02:42 by cdahlia           #+#    #+#             */
/*   Updated: 2021/07/30 19:02:42 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	sym;
	char			*str;
	size_t			i;

	sym = (unsigned char)c;
	str = (char *)b;
	i = 0;
	while ((i < len))
	{
		*(str + i) = sym;
		i++;
	}
	return (b);
}
