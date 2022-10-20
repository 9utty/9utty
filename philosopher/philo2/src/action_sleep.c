/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:12:59 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 02:29:48 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	action_sleep(t_philo *philo, t_table *table)
{
	if (state_print(philo, table, SLEEPING_E) == FALSE_E)
	{
		write(1, "sleep\n", 6);
		return (FALSE_E);
	}
	thread_pause(table->time_to_sleep);
	if (state_print(philo, table, THINKING_E) == FALSE_E)
	{
		write(1, "think\n", 6);
		return (FALSE_E);
	}
	return (TRUE_E);
}
