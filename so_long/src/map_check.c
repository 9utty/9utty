/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:55:19 by gulee             #+#    #+#             */
/*   Updated: 2022/06/30 03:45:22 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	func_ptr(int (**f)(t_data *data))
{
	f[0] = &parsing_map_value;
	f[1] = &parsing_map_value_validi;
	f[2] = &parsing_map_square;
	f[3] = &parsing_map_wall;
}

int	check_map(t_data *data)
{
	int		(*f[4])(t_data *data);
	int		index;

	index = 0;
	if (data == NULL)
		return (FALSE_E);
	func_ptr(f);
	while (index < 4)
	{
		if (f[index](data) == FALSE_E)
			return (FALSE_E);
		++index;
	}
	return (TRUE_E);
}
