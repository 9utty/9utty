/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:43:09 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 10:42:47 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd >= 0)
	{
		while (s && *s)
		{
			write(fd, &*s, 1);
			s++;
		}
	}
}

void	ft_putnbr_fd(ssize_t len, int fd)
{
	if (len < 0)
	{
		len *= -1;
		ft_putchar_fd('-', fd);
	}
	if (len >= 10)
	{
		ft_putnbr_fd(len / 10, fd);
		ft_putnbr_fd(len % 10, fd);
	}
	else
	{
		if (fd >= 0)
			ft_putchar_fd(len + '0', fd);
	}
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
