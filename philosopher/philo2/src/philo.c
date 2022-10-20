/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:51:34 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 03:36:38 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	memset(&table, 0, sizeof(t_table));
	if (check_arg(argc, argv) == FALSE_E)
		return (error_print("Arguments"));
	set_table(argc, argv, &table);
	if (set_philo(&table) == FALSE_E)
		return (error_print("Philo Set-up"));
	set_mutex(&table);
	gettimeofday(&table.start, NULL);
	if (start_philo(&table) == FALSE_E)
	{
		destroy_mutex(&table);
		all_free(&table.fork_mutex, &table.philo);
		return (error_print("Pthread Create"));
	}
	if (pthread_create(&table.check, NULL, &check_philo, \
		&table.philo[0]) == 0)
	{
		detach(&table);
		pthread_detach(table.check);
		destroy_mutex(&table);
		all_free(table.philo, table.fork_mutex);
	}
	return (0);
}
