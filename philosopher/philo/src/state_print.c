/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 08:43:10 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 10:39:02 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	str_init(char **str)
{
	str[0] = ft_strdup("\033[0;33mhas taken a fork");
	str[1] = ft_strdup("\033[0;32mis eating");
	str[2] = ft_strdup("\033[0;34mis sleeping");
	str[3] = ft_strdup("\033[0;35mis thinking");
	str[4] = ft_strdup("\033[0;31mdied");
}

static void	str_free(char **str)
{
	int	index;

	index = 0;
	while (index < 5)
	{
		free(str[index]);
		str[index] = NULL;
		++index;
	}
}

char	**get_str(void)
{
	static char	*str[5];

	str_init(str);
	return (str);
}

void	state_print(t_philo *philo, t_action action, char **str)
{
	ssize_t	time;

	pthread_mutex_lock(&philo->table->finish_mutex);
	pthread_mutex_lock(&philo->table->die_mutex);
	if ((int)philo->eat_count == philo->table->must_eat_count \
		|| philo->table->stop)
	{
		pthread_mutex_unlock(&philo->table->die_mutex);
		pthread_mutex_unlock(&philo->table->finish_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->table->die_mutex);
	pthread_mutex_unlock(&philo->table->finish_mutex);
	time = time_to_time() - philo->table->start_time;
	printf("%7zd ms    %-3d ", time, philo->philo_id);
	if (action == EATING_E)
	{
		printf("%s, eat_count: %-3d\n", str[1], philo->eat_count + 1);
		philo->eat_count++;
	}
	else
		printf("%s\n", str[action]);
	printf("\033[0m");
	str_free(str);
}
