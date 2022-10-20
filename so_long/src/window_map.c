/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:13:50 by gulee             #+#    #+#             */
/*   Updated: 2022/07/07 16:12:32 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_read(t_data *data)
{
	data->img_ground = mlx_xpm_file_to_image(data->mlx, \
	"./assets/tile00.xpm", &data->img_wid, &data->img_hgt);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, \
	"./assets/wall00.xpm", &data->img_wid, &data->img_hgt);
	data->img_player = mlx_xpm_file_to_image(data->mlx, \
	"./assets/player.xpm", &data->img_wid, &data->img_hgt);
	data->img_collec = mlx_xpm_file_to_image(data->mlx, \
	"./assets/ball.xpm", &data->img_wid, &data->img_hgt);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, \
	"./assets/exit00.xpm", &data->img_wid, &data->img_hgt);
}

void	window_map(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	img_read(data);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			put_img(data, data->img_ground, x, y);
			if (data->map[y][x] == '1')
				put_img(data, data->img_wall, x, y);
			else if (data->map[y][x] == 'C')
				put_img(data, data->img_collec, x, y);
			else if (data->map[y][x] == 'P')
				put_player_img(data, x, y);
			else if (data->map[y][x] == 'E')
				put_img(data, data->img_exit, x, y);
			++x;
		}
		++y;
	}
}
