/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_to_job.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:59:02 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 03:46:13 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->exit_mutex);
	if (philo->table->flag)
	{
		pthread_mutex_unlock(&philo->table->exit_mutex);
		return (FALSE_E);
	}
	pthread_mutex_unlock(&philo->table->exit_mutex);
	return (TRUE_E);
}

void	*philo_to_job(void *arg)
{
	t_table	*a;
	t_philo	*philo;
	t_bool	tmp;

	philo = arg;
	a = philo->table;
	if (philo->philo_id % 2 != 0)
		usleep(800);
	gettimeofday(&philo->last_eat, NULL);
	while (check_die(philo))
	{
		if (action_get_fork(philo, a) == FALSE_E)
		{
			write(1, "end1\n", 5);
			return (NULL);
		}
		tmp = action_eat(philo, a);
		if (tmp == FALSE_E)
		{
			write(1, "end2\n", 5);
			return (NULL);
		}
		else if (tmp == FINISH_E)
			return (NULL);
		if (action_sleep(philo, a) == FALSE_E)
		{
			write(1, "end3\n", 5);
			return (NULL);
		}
	}
	return (NULL);
}
