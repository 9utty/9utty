/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:09:27 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 02:31:01 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	action_get_fork(t_philo *philo, t_table *table)
{
	int	philos;

	philos = table->number_of_philosophers;
	pthread_mutex_lock(&table->fork_mutex[philo->philo_id]);
	if (state_print(philo, table, FORK_E) == FALSE_E)
	{
		write(1, "fork\n", 1);
		return (FALSE_E);
	}
	if (philo->philo_id == philos - 1)
		pthread_mutex_lock(&table->fork_mutex[0]);
	else
		pthread_mutex_lock(&table->fork_mutex[philo->philo_id + 1]);
	if (state_print(philo, table, FORK_E) == FALSE_E)
	{
		write(1, "fork\n", 1);
		return (FALSE_E);
	}
	return (TRUE_E);
}

void	action_put_fork(t_philo *philo, t_table *table)
{
	int	philos;

	philos = table->number_of_philosophers;
	pthread_mutex_unlock(&table->fork_mutex[philo->philo_id]);
	if (philo->philo_id == philos - 1)
		pthread_mutex_unlock(&table->fork_mutex[0]);
	else
		pthread_mutex_unlock(&table->fork_mutex[philo->philo_id + 1]);
}
