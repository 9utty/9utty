/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:17:44 by gulee             #+#    #+#             */
/*   Updated: 2022/08/05 00:34:00 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_mutex(t_table *table)
{
	int	index;
	int	philos;

	index = 0;
	philos = table->number_of_philosophers;
	pthread_mutex_init(&table->print_mutex, NULL);
	while (index < philos)
	{
		pthread_mutex_init(&table->fork_mutex[index], NULL);
		++index;
	}
}
