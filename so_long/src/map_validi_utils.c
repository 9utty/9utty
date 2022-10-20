/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validi_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:49:19 by gulee             #+#    #+#             */
/*   Updated: 2022/07/13 21:08:15 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parsing_map_value(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] != '1' && data->map[y][x] != '0' && \
			data->map[y][x] != 'C' && data->map[y][x] != 'E' && \
			data->map[y][x] != 'P')
				return (FALSE_E);
			++x;
		}
		++y;
	}
	data->hgt = y;
	data->wid = x;
	return (TRUE_E);
}

int	parsing_map_value_validi(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				data->item_count += 1;
			if (data->map[y][x] == 'E')
				data->exit_count += 1;
			if (data->map[y][x] == 'P')
				data->player_count += 1;
			++x;
		}
		++y;
	}
	if (data->item_count < 1 || data->exit_count < 1 || data->player_count != 1)
		return (FALSE_E);
	return (TRUE_E);
}

int	parsing_map_square(t_data *data)
{
	int		x;
	int		y;
	char	**tmp;

	tmp = data->map;
	y = 0;
	while (tmp[y])
	{
		x = 0;
		while (tmp[y][x])
			++x;
		if (x != data->wid)
			return (FALSE_E);
		++y;
	}
	return (TRUE_E);
}

int	parsing_map_wall(t_data *data)
{
	int		x;
	int		y;
	char	**tmp;

	y = 0;
	x = 0;
	tmp = data->map;
	while (tmp[y])
	{
		while (tmp[y][x])
		{
			if (tmp[0][x] != '1' || tmp[data->hgt - 1][x] != '1')
				return (FALSE_E);
			++x;
		}
		if (tmp[y][0] != '1' || tmp[y][data->wid - 1] != '1')
			return (FALSE_E);
		++y;
	}
	return (TRUE_E);
}
