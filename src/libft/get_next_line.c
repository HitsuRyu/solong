/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:04:43 by cdahlia           #+#    #+#             */
/*   Updated: 2021/07/30 19:04:43 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 64

static int	ft_newline(char *part)
{
	int	i;

	i = 0;
	if (!part)
		return (0);
	while (part[i])
	{
		if (part[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_getline(char *part)
{
	char	*retline;
	int		i;

	i = 0;
	if (!part)
		return (NULL);
	while (part[i] && part[i] != '\n')
		i++;
	retline = (char *)malloc(sizeof(char) * (i + 1));
	if (!retline)
		return (NULL);
	i = 0;
	while (part[i] && part[i] != '\n')
	{
		retline[i] = part[i];
		i++;
	}
	retline[i] = '\0';
	return (retline);
}

static char	*ft_getpart(char *part)
{
	char	*retline;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!part)
		return (NULL);
	while (part[i] && part[i] != '\n')
		i++;
	if (!part[i])
	{
		free(part);
		return (NULL);
	}
	retline = (char *)malloc(sizeof(char) * (ft_strlen(part) - i + 1));
	if (!retline)
		return (NULL);
	i++;
	while (part[i])
		retline[j++] = part[i++];
	retline[j] = '\0';
	free(part);
	return (retline);
}

static int	ft_readline(int fd, char *buf, char **line)
{
	int			ret;
	static char	*part;
	char		*tmp;

	ret = 1;
	while (!ft_newline(part) && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		tmp = part;
		part = ft_strjoin(part, buf);
		free(tmp);
	}
	*line = ft_getline(part);
	part = ft_getpart(part);
	free(buf);
	if (!ret)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	return (ft_readline(fd, buf, line));
}
