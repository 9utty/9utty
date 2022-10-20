/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lib_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 08:19:45 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 17:25:09 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

ssize_t	ft_atoi(const char *str)
{
	size_t	result;
	ssize_t	negative;

	result = 0;
	negative = 1;
	while (*str != '\0' && (ft_isspace(*str)))
		str++;
	if (*str != '\0' && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * negative);
}

int	die_check(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->table->die_mutex);
	if (i)
		philo->table->stop = i;
	if (philo->table->stop)
	{
		pthread_mutex_unlock(&philo->table->die_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->die_mutex);
	return (0);
}

ssize_t	time_to_time(void)
{
	ssize_t				time;
	struct timeval		current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		error_print("Time\n");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	philo_pause(ssize_t time_in_ms)
{
	ssize_t	start_time;

	start_time = 0;
	start_time = time_to_time();
	while ((time_to_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
