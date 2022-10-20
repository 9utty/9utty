/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_thread_pause.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:21:32 by gulee             #+#    #+#             */
/*   Updated: 2022/08/05 01:06:35 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_pause(int ms)
{
	t_timeval	start;

	gettimeofday(&start, NULL);
	while (sleep_time_diff(&start) < ms)
	{
		usleep(250);
	}
}
