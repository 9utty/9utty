/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:17:30 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 03:26:09 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	chec_check_go(t_table *table)
{
	int	index;
	int	time;
	int	philos;

	index = 0;
	philos = table->number_of_philosophers;
	while (1)
	{
		gettimeofday(&table->check_time, NULL);
		usleep(2500);
		time = check_time_diff(&table->philo[index], &table->check_time);
		if (time >= table->time_to_die)
		{
			state_print(&table->philo[index], table, DIED_E);
			detach(table);
			break ;
		}
		++index;
		if (index == philos)
			index = 0;
	}
}

void	*check_philo(void *arg)
{
	t_table	*table;
	t_philo	*philo;

	philo = (t_philo *)arg;
	table = philo->table;
	chec_check_go(table);
	return (NULL);
}
