/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 08:36:27 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 10:40:11 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_ptr *ptr)
{
	pthread_mutex_init(&ptr->table.print_mutex, NULL);
	pthread_mutex_init(&ptr->table.die_mutex, NULL);
	pthread_mutex_init(&ptr->table.eat_time_mutex, NULL);
	pthread_mutex_init(&ptr->table.finish_mutex, NULL);
}

int	init(t_ptr *ptr)
{
	int	i;

	i = 0;
	ptr->table.start_time = time_to_time();
	ptr->table.stop = 0;
	ptr->table.finish_count = 0;
	init_mutex(ptr);
	while (i < ptr->table.philo_max)
	{
		ptr->philo[i].philo_id = i + 1;
		ptr->philo[i].last_eat_time = ptr->table.start_time;
		ptr->philo[i].eat_count = 0;
		ptr->philo[i].finish = 0;
		ptr->philo[i].right_fork = NULL;
		pthread_mutex_init(&ptr->philo[i].left_fork, NULL);
		if (ptr->table.philo_max == 1)
			return (1);
		if (i == ptr->table.philo_max - 1)
			ptr->philo[i].right_fork = &ptr->philo[0].left_fork;
		else
			ptr->philo[i].right_fork = &ptr->philo[i + 1].left_fork;
		i++;
	}
	return (1);
}
