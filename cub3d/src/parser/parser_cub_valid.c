/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cub_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:51:24 by gulee             #+#    #+#             */
/*   Updated: 2022/09/28 08:23:41 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_bool	file_expention(char *to, char *find)
{
	if (ft_strncmp(to[ft_strlen(to) - 4], ".cub", 4) != 0)
		return (FALSE_E);
	else
		return (TRUE_E);
}

static void	valid_cub_color(char **cub, int *index)
{
	int	value_count;
	int	tmp_index;
	int	tmp;

	value_count = 0;
	tmp_index = *index;
	tmp = *index + 2;
	while (*index < tmp && cub[*index])
	{
		if (ft_strncmp(cub[*index], "F ", 2) == 0 \
			|| ft_strncmp(cub[*index], "C ", 2) == 0)
			++value_count;
		++(*index);
	}
	if (*index - tmp_index != value_count && value_count != 2)
		err_put();
}

static void	valid_cub_text(char **cub, int *index)
{
	int	value_count;

	value_count = 0;
	while (*index < 4 && cub[*index])
	{
		if (ft_strncmp(cub[*index], "SO ", 3) == 0 \
			|| ft_strncmp(cub[*index], "NO ", 3) == 0 \
			|| ft_strncmp(cub[*index], "EA ", 3) == 0 \
			|| ft_strncmp(cub[*index], "WE ", 3) == 0)
			++value_count;
		++(*index);
	}
	if (value_count != 4 && *index != value_count)
		err_put();
	if (*index == 0)
		err_put();
}

void	valid_cub_value(char **cub)
{
	int	index;

	index = 0;
	valid_cub_text(cub, &index);
	while (cub[index] && ft_strcmp(cub[index], "\n") == 0)
		++index;
	valid_cub_color(cub, &index);
	while (cub[index] && ft_strcmp(cub[index], "\n") == 0)
		++index;
	if (!cub[index])
		err_put();
}
