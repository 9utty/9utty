/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_eat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:18:55 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 02:30:33 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	action_eat(t_philo *philo, t_table *table)
{
	if (state_print(philo, table, EATING_E) == FALSE_E)
	{
		write(1, "eat\n", 4);
		return (FALSE_E);
	}
	gettimeofday(&philo->last_eat, NULL);
	thread_pause(table->time_to_eat);
	action_put_fork(philo, table);
	return (TRUE_E);
}
