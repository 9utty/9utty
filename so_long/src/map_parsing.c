/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:43:19 by gulee             #+#    #+#             */
/*   Updated: 2022/07/12 18:34:32 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

static char	*map_parsing(int fd)
{
	char	*temp;
	char	*buff;
	char	*str;

	str = get_next_line(fd);
	if (!str)
		return (NULL);
	temp = ft_strdup("");
	if (!temp)
	{
		free(str);
		return (NULL);
	}
	while (str)
	{
		buff = temp;
		temp = ft_strjoin(temp, str);
		if (!temp)
			return (NULL);
		free(buff);
		free(str);
		str = get_next_line(fd);
	}
	return (temp);
}

void	map_read(t_data *data, char *file_name)
{
	char	*line;
	int		fd;
	int		return_value;

	return_value = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_all(NULL);
	line = map_parsing(fd);
	if (!line)
		error_all(NULL);
	data->map = ft_split(line, '\n');
	free(line);
	if (data->map == NULL)
		error_all(NULL);
	return_value = check_map(data);
	if (return_value == FALSE_E)
		error_all(data);
	close(fd);
}
