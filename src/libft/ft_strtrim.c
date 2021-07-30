/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:03:11 by cdahlia           #+#    #+#             */
/*   Updated: 2021/07/30 19:03:11 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkchar(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

static char	*ft_first(char *str, char *set)
{
	size_t	i;
	char	*first;

	first = NULL;
	i = 0;
	while (str[i] && ft_checkchar(str[i], set))
	{
		first = str + i;
		i++;
	}
	if (first != NULL)
		return (first + 1);
	return (NULL);
}

static char	*ft_last(char *str, char *set)
{
	size_t	i;
	char	*last;

	last = NULL;
	i = ft_strlen(str) - 1;
	while (str[i] && ft_checkchar(str[i], set))
	{
		last = str + i;
		i--;
	}
	return (last);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*first;
	char	*last;
	char	*trim;

	trim = NULL;
	first = ft_first((char *)s1, (char *)set);
	last = ft_last((char *)s1, (char *)set);
	if (first != NULL && last != NULL && first < last)
		trim = ft_substr((char *)s1, first - (char *)s1, last - first);
	else if (first == NULL && last != NULL)
		trim = ft_substr((char *)s1, 0, last - (char *)s1);
	else if (first != NULL && last == NULL)
		trim = ft_substr((char *)s1, first - (char *)s1, ft_strlen((char *)s1));
	else if (first == NULL && last == NULL)
		trim = ft_substr(s1, 0, ft_strlen((char *)s1));
	else if (first >= last)
		trim = ft_substr(s1, 0, 0);
	return (trim);
}
