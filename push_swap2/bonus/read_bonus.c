/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:37:20 by gulee             #+#    #+#             */
/*   Updated: 2022/07/26 10:23:13 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*read_order(int fd)
{
	int		read_size;
	char	*tmp;
	char	c;

	tmp = malloc(sizeof(char) * 5);
	if (tmp == NULL)
		return (NULL);
	read_size = read(fd, tmp, 3);
	if (read_size <= 0)
		return (NULL);
	if (tmp[2] == '\n')
		tmp[2] = '\0';
	else if (tmp[2] != '\0' && tmp[0] >= 'a' && tmp[0] <= 'z')
	{
		read_size = read(fd, &c, 1);
		tmp[3] = '\0';
		return (tmp);
	}
	return (tmp);
}
