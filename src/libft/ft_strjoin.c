/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:02:57 by cdahlia           #+#    #+#             */
/*   Updated: 2021/07/30 19:02:57 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1)
	{
		res = ft_strdup((char *)s2);
		return (res);
	}
	i = 0;
	j = 0;
	len = ft_strlen((char *)s1);
	res = (char *)malloc((len + ft_strlen((char *)s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
		res[i++] = s1[j++];
	j = 0;
	len = ft_strlen((char *)s2);
	while (j < len)
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
