/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:39:46 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 02:21:39 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	start_philo(t_table *table)
{
	int	index;
	int	philos;

	index = 0;
	philos = table->number_of_philosophers;
	while (index < philos)
	{
		table->philo[index].philo_id = index;
		table->philo[index].table = table;
		if (pthread_create(&table->philo[index].thread_id, NULL, \
				&philo_to_job, &table->philo[index]) != 0)
			return (FALSE_E);
		++index;
	}
	return (TRUE_E);
}
