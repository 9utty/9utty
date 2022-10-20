/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:11:29 by gulee             #+#    #+#             */
/*   Updated: 2022/08/05 01:13:43 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	set_philo(t_table *table)
{
	int		philos;
	t_philo	*temp_philo;
	t_mutex	*temp_mutex;

	philos = table->number_of_philosophers;
	temp_philo = malloc((philos + 1) * sizeof(t_philo));
	if (temp_philo == NULL)
		return (FALSE_E);
	memset(temp_philo, 0, ((philos + 1) * sizeof(t_philo)));
	table->philo = temp_philo;
	temp_mutex = malloc((philos + 1) * sizeof(t_mutex));
	if (temp_mutex == NULL)
		return (FALSE_E);
	memset(temp_mutex, 0, ((philos + 1) * sizeof(t_mutex)));
	table->fork_mutex = temp_mutex;
	return (TRUE_E);
}
