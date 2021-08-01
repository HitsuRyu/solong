/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:02:51 by cdahlia           #+#    #+#             */
/*   Updated: 2021/07/30 19:02:51 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **tmp)
{
	size_t	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (NULL);
}

static size_t	ft_count_strs(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	if (s == NULL)
		return (0);
	i = 0;
	counter = 0;
	while (s[i] && s[i] == c)
	{
		i++;
	}
	while (s[i])
	{
		if (s[i] == c)
		{
			counter++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		counter++;
	return (counter);
}

static void	ft_nextstr(char **next_str, size_t *next_str_len, char c)
{
	size_t	i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

static char	**ft_strtoa(char **tmp, char *next_str, size_t counter, char c)
{
	size_t	i;
	size_t	next_str_len;

	i = 0;
	next_str_len = 0;
	while (i < counter)
	{
		ft_nextstr(&next_str, &next_str_len, c);
		tmp[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));
		if (!tmp)
			return (ft_free(tmp));
		ft_strlcpy(tmp[i], next_str, next_str_len + 1);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	char	*next_str;
	size_t	counter;

	if (s == NULL)
		return (NULL);
	if (s[0] == '\0' && c != '\0')
	{
		tmp = (char **)malloc(sizeof(char *));
		tmp[0] = NULL;
		return (tmp);
	}
	counter = ft_count_strs(s, c);
	tmp = malloc(sizeof(char *) * (counter + 1));
	if (!tmp)
		return (NULL);
	next_str = (char *)s;
	ft_strtoa(tmp, next_str, counter, c);
	return (tmp);
}
