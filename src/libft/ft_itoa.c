/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:02:15 by cdahlia           #+#    #+#             */
/*   Updated: 2021/07/30 19:02:15 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_strrev(char *str)
{
	char	c;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (j > i)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}

static char	*ft_mas(int n, long int num, size_t nlen, char *buf)
{
	size_t	i;

	i = 0;
	while (i < nlen)
	{
		buf[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	if (n < 0)
	{
		buf[i] = '-';
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

char	*ft_itoa(int n)
{
	char		*buf;
	long int	num;
	size_t		nlen;

	buf = NULL;
	num = n;
	nlen = ft_intlen(num);
	if (num < 0)
	{
		buf = malloc((nlen + 2) * sizeof(char));
		num = (-1) * num;
	}
	else
		buf = malloc((nlen + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ft_mas(n, num, nlen, buf);
	return (ft_strrev(buf));
}
