/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_times.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:58:50 by gulee             #+#    #+#             */
/*   Updated: 2022/08/05 01:06:57 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_time_diff(t_table *table)
{
	t_timeval	right_now;
	double		sec;
	double		usec;

	gettimeofday(&right_now, NULL);
	sec = right_now.tv_sec - table->start.tv_sec;
	usec = right_now.tv_usec - table->start.tv_usec;
	return (sec * 1000 + usec / 1000);
}

int	check_time_diff(t_philo *philo, t_timeval *time)
{
	double	sec;
	double	usec;

	sec = time->tv_sec - philo->last_eat.tv_sec;
	usec = time->tv_usec - philo->last_eat.tv_usec;
	return (sec * 1000 + usec / 1000);
}

int	sleep_time_diff(t_timeval *start)
{
	t_timeval	right_now;
	double		sec;
	double		usec;

	gettimeofday(&right_now, NULL);
	sec = right_now.tv_sec - start->tv_sec;
	usec = right_now.tv_usec - start->tv_usec;
	return (sec * 1000000 + usec);
}
