/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:27:27 by gulee             #+#    #+#             */
/*   Updated: 2022/06/30 23:55:38 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	index;

	index = 0;
	while (map[index])
	{
		free(map[index]);
		++index;
	}
	free(map);
}

void	error_all(t_data *data)
{
	if (data != NULL)
		free_map(data->map);
	printf("Error\n");
	exit(1);
}

void	error_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->window);
	error_all(data);
}
