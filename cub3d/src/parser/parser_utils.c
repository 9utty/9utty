/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 07:33:21 by gulee             #+#    #+#             */
/*   Updated: 2022/09/28 07:35:14 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	index_line(char *filename)
{
	int		index;
	int		fd;
	char	*line;

	index = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		err_put();
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		++index;
		line = get_next_line(fd);
	}
	close(fd);
	return (index);
}
