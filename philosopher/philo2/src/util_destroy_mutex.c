/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_destroy_mutex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:37:28 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 03:37:17 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_table *table)
{
	int	index;
	int	philos;

	index = 0;
	philos = table->number_of_philosophers;
	pthread_mutex_destroy(&table->print_mutex);
	while (index < philos)
	{
		pthread_mutex_destroy(&table->fork_mutex[index]);
		++index;
	}
}
