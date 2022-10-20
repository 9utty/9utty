/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:43:16 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 10:26:38 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parser(int argc, char **argv, t_ptr *ptr)
{
	if (argc == 5 || argc == 6)
	{
		ptr->table.philo_max = ft_atoi(argv[1]);
		ptr->table.time_to_die = ft_atoi(argv[2]);
		ptr->table.time_to_eat = ft_atoi(argv[3]);
		ptr->table.time_to_sleep = ft_atoi(argv[4]);
		ptr->table.must_eat_count = -1;
		if (argc == 6)
			ptr->table.must_eat_count = ft_atoi(argv[5]);
		if (ptr->table.philo_max <= 0 || ptr->table.time_to_die <= 0 \
			|| ptr->table.time_to_eat <= 0 || ptr->table.time_to_sleep <= 0)
			return (0);
		return (1);
	}
	return (0);
}
