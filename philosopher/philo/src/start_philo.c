/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:42:53 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 17:25:43 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*is_dead(void	*data)
{
	t_philo					*philo;

	philo = (t_philo *)data;
	philo_pause(philo->table->time_to_die + 1);
	pthread_mutex_lock(&philo->table->eat_time_mutex);
	pthread_mutex_lock(&philo->table->finish_mutex);
	if (!die_check(philo, 0) && !philo->finish && ((time_to_time() \
	- philo->last_eat_time) >= (long)(philo->table->time_to_die)))
	{
		pthread_mutex_unlock(&philo->table->eat_time_mutex);
		pthread_mutex_unlock(&philo->table->finish_mutex);
		pthread_mutex_lock(&philo->table->print_mutex);
		state_print(philo, DIED_E, get_str());
		pthread_mutex_unlock(&philo->table->print_mutex);
		die_check(philo, 1);
	}
	pthread_mutex_unlock(&philo->table->eat_time_mutex);
	pthread_mutex_unlock(&philo->table->finish_mutex);
	return (NULL);
}

void	*thread(void *data)
{
	t_philo					*philo;

	philo = (t_philo *)data;
	if (philo->philo_id % 2 == 0)
		philo_pause(philo->table->time_to_eat / 10);
	while (!die_check(philo, 0))
	{
		pthread_create(&philo->thread_die, NULL, is_dead, data);
		action(philo);
		pthread_detach(philo->thread_die);
		if ((int)philo->eat_count == philo->table->must_eat_count)
		{
			pthread_mutex_lock(&philo->table->finish_mutex);
			philo->finish = 1;
			philo->table->finish_count++;
			if (philo->table->finish_count == philo->table->philo_max)
			{
				pthread_mutex_unlock(&philo->table->finish_mutex);
				die_check(philo, 2);
			}
			pthread_mutex_unlock(&philo->table->finish_mutex);
			return (NULL);
		}
	}
	return (NULL);
}

int	start(t_ptr *ptr)
{
	int	i;

	i = 0;
	while (i < ptr->table.philo_max)
	{
		ptr->philo[i].table = &ptr->table;
		if (pthread_create(&ptr->philo[i].thread_id, NULL, thread, \
			&ptr->philo[i]) != 0)
			return (error_print("Pthread return 0\n"));
		i++;
	}
	return (1);
}
