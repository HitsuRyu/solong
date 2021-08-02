/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 19:02:47 by cdahlia           #+#    #+#             */
/*   Updated: 2021/07/30 19:02:47 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
		ft_putnbr_fd(n, fd);
	}
	else if (n < 10)
	{
		c = n + 48;
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		c = n % 10 + 48;
		write(fd, &c, 1);
	}
}
