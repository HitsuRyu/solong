/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:03:36 by cdahlia           #+#    #+#             */
/*   Updated: 2021/08/02 12:59:38 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_cleaner(int errno, char **map)
{
	int	i;

	i = 0;
	if (errno == 1)
		write(1, "Error\nWalls error.\n", 19);
	if (errno == 2)
		write(1, "Error\nSize error.\n", 18);
	if (errno == 3)
		write(1, "Error\nContent error.\n", 21);
	if (errno == 4)
		write(1, "Error\nMLX init error.\n", 22);
	while (map[i] >= (char *) NULL)
	{
		free(map[i]);
		if (map[i] == NULL)
			break ;
		i++;
	}
	exit (-1);
}

static int	str_counter(char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		i++;
		free(line);
	}
	free(line);
	get_next_line(fd, &line);
	free(line);
	i++;
	close(fd);
	return (i);
}

static void	check_filename(char *filename, int fd)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
	{
		write(1, "invalid file\n", 13);
		close(fd);
		exit(-1);
	}
	if (filename[len - 1] != 'r' || filename[len - 2] != 'e' \
	|| filename[len - 3] != 'b' || filename[len - 4] != '.')
	{
		write(1, "invalid file\n", 13);
		close(fd);
		exit(-1);
	}
	if (read(fd, NULL, 0) == -1)
	{
		write(1, "invalid file\n", 13);
		close(fd);
		exit(-1);
	}
}

char	**map_parser(char *filename)
{
	char	**map;
	int		strs;
	int		fd;
	int		i;

	i = 0;
	map = NULL;
	fd = open(filename, O_RDONLY);
	check_filename(filename, fd);
	strs = str_counter(filename);
	map = malloc(sizeof(char *) * strs + 1);
	if (!map)
		exit(-1);
	while (i < strs)
		get_next_line(fd, &map[i++]);
	close(fd);
	map[i] = NULL;
	check_walls(map);
	check_len(map);
	check_content(map);
	return (map);
}
