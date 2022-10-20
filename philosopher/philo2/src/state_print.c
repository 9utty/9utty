/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:12:11 by gulee             #+#    #+#             */
/*   Updated: 2022/08/28 23:12:36 by gulee            ###   ########.fr       */
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

t_bool	state_print(t_philo *philo, t_table *table, t_state state)
{
	char	*str[5];

	str_init(str);
	pthread_mutex_lock(&table->print_mutex);
	table->curr_time = print_time_diff(table);
	printf("%7d ms    %-3d ", table->curr_time, philo->philo_id + 1);
	if (state == EATING_E)
	{
		printf("%s, eat_count: %-3d\n", str, philo->eat_count + 1);
	}
	else
		printf("%s\n", str[state]);
	printf("\033[0m");
	str_free(str);
	pthread_mutex_unlock(&table->print_mutex);
	return (TRUE_E);
}
