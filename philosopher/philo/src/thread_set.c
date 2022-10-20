/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 02:14:59 by gulee             #+#    #+#             */
/*   Updated: 2022/08/30 01:43:36 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_bool	thread_set(t_philo_table *table)
{
	t_temp	*temp;
	int		index;
	int		state;

	index = 1;
	while (index <= table->number_of_philosophers)
	{
		temp = malloc(sizeof(t_temp));
		if (temp == NULL)
			error_print("Thread seting");
		temp->table = table;
		temp->philo = table->first_philo;
		state = pthread_create(&(temp->philo->thread_id), NULL, )
	}
}
