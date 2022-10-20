/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:38:26 by gulee             #+#    #+#             */
/*   Updated: 2022/07/12 18:41:31 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	so_long(t_data *data)
{
	data->window = mlx_new_window(data->mlx, data->wid * 64, \
	data->hgt * 64, "so_long");
	if (!data->window)
		error_game(data);
	window_map(data);
	mlx_hook(data->window, 2, 0, move_key, data);
	mlx_hook(data->window, 17, 0, so_long_exit, data);
	mlx_loop(data->mlx);
}

static void	struct_init(t_data *data)
{
	data->map = NULL;
	data->window = NULL;
	data->img_ground = NULL;
	data->img_wall = NULL;
	data->img_player = NULL;
	data->img_collec = NULL;
	data->img_exit = NULL;
	data->player_x = 0;
	data->player_y = 0;
	data->img_hgt = 0;
	data->img_wid = 0;
	data->exit_count = 0;
	data->exit_x = 0;
	data->exit_y = 0;
	data->item_count = 0;
	data->player_count = 0;
	data->hgt = 0;
	data->wid = 0;
	data->move_count = 0;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		error_all(&data);
	struct_init(&data);
	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
	{
		printf("Error\n");
		return (0);
	}
	map_read(&data, argv[1]);
	so_long(&data);
	return (0);
}
