/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:58:50 by gulee             #+#    #+#             */
/*   Updated: 2022/07/01 01:18:28 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_move(t_data *data, int y, int x)
{
	char	**tmp;

	tmp = data->map;
	if (tmp[y][x] != '1')
	{
		if (tmp[y][x] == 'C')
		{
			put_img(data, data->img_ground, x, y);
			data->item_count -= 1;
			tmp[y][x] = '0';
		}
		if (data->item_count != 0 && tmp[y][x] == 'E')
			return ;
		data->move_count += 1;
		printf("%d\n", data->move_count);
		if (data->item_count == 0 && tmp[y][x] == 'E')
			so_long_exit(data);
		put_img(data, data->img_ground, data->player_x, data->player_y);
		put_img(data, data->img_player, x, y);
		data->player_x = x;
		data->player_y = y;
	}
}

int	move_key(int key_num, t_data *data)
{
	if (key_num == 13)
		move_move(data, data->player_y - 1, data->player_x);
	else if (key_num == 0)
		move_move(data, data->player_y, data->player_x - 1);
	else if (key_num == 1)
		move_move(data, data->player_y + 1, data->player_x);
	else if (key_num == 2)
		move_move(data, data->player_y, data->player_x + 1);
	else if (key_num == 53)
		so_long_exit(data);
	return (0);
}
