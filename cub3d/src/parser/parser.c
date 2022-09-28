/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:51:26 by gulee             #+#    #+#             */
/*   Updated: 2022/09/28 08:24:52 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	get_cub(t_table *table)
{
	int	len;
	int	fd;
	int	index;

	index = 0;
	len = line_count(table->map.filename);
	table->cub = malloc(sizeof(char *) * (len + 1));
	if (!table->cub)
		err_put();
	fd = open(table->map.filename, O_RDONLY);
	if (fd == -1)
		err_put();
	table->cub[index] = get_next_line(fd);
	while (index < len && table->cub[++index])
		table->cub[index] = get_next_line(fd);
	table->cub[index] = NULL;
	close(fd);
}

void	parser(t_table *table)
{
	if (file_expention(table->map.filename, ".cub") == FALSE_E)
		err_put();
	get_cub(table);
	valid_cub_value(table->cub);
	get_map(table);
}
