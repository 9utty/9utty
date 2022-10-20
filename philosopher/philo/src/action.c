/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:43:19 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 10:54:43 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print_mutex);
	state_print(philo, SLEEPING_E, get_str());
	pthread_mutex_unlock(&philo->table->print_mutex);
	philo_pause(philo->table->time_to_sleep);
	pthread_mutex_lock(&philo->table->print_mutex);
	state_print(philo, THINKING_E, get_str());
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	action(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->table->print_mutex);
	state_print(philo, FORK_E, get_str());
	pthread_mutex_unlock(&philo->table->print_mutex);
	if (!philo->right_fork)
	{
		philo_pause(philo->table->time_to_die * 2);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->table->print_mutex);
	state_print(philo, FORK_E, get_str());
	pthread_mutex_unlock(&philo->table->print_mutex);
	pthread_mutex_lock(&philo->table->print_mutex);
	state_print(philo, EATING_E, get_str());
	pthread_mutex_lock(&philo->table->eat_time_mutex);
	philo->last_eat_time = time_to_time();
	pthread_mutex_unlock(&philo->table->eat_time_mutex);
	pthread_mutex_unlock(&philo->table->print_mutex);
	philo_pause(philo->table->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
	sleep_think(philo);
}
