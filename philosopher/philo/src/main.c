/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 07:43:02 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 10:54:46 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	die_check2(t_ptr *ptr)
{
	pthread_mutex_lock(&ptr->table.die_mutex);
	if (ptr->table.stop)
	{
		pthread_mutex_unlock(&ptr->table.die_mutex);
		return (1);
	}
	pthread_mutex_unlock(&ptr->table.die_mutex);
	return (0);
}

static void	stop(t_ptr *ptr)
{
	int	i;

	i = -1;
	while (!die_check2(ptr))
		philo_pause(1);
	while (++i < ptr->table.philo_max)
		pthread_join(ptr->philo[i].thread_id, NULL);
	pthread_mutex_destroy(&ptr->table.print_mutex);
	i = -1;
	while (++i < ptr->table.philo_max)
		pthread_mutex_destroy(&ptr->philo[i].left_fork);
	free(ptr->philo);
}

int	main(int argc, char **argv)
{
	t_ptr		ptr;

	memset(&ptr, 0, sizeof(t_ptr));
	if (check_arg(argc, argv) == FALSE_E)
		return (error_print("Arguments\n"));
	if (!(parser(argc, argv, &ptr)))
		return (error_print("Parser\n"));
	ptr.philo = malloc(sizeof(t_philo) * ptr.table.philo_max);
	if (!ptr.philo)
		return (error_print("Allocate\n"));
	if (!init(&ptr) || !start(&ptr))
	{
		free(ptr.philo);
		return (0);
	}
	stop(&ptr);
}
