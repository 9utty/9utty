/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_detach.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 01:04:42 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 03:39:25 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	detach(t_table *table)
{
	int		index;
	int		philos;

	index = 0;
	philos = table->number_of_philosophers;
	while (index < philos)
	{
		if (table->philo[index].thread_id != NULL)
			pthread_join(table->philo[index].thread_id, NULL);
		++index;
	}
}
