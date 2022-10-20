/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 21:29:44 by gulee             #+#    #+#             */
/*   Updated: 2022/08/26 03:34:00 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef enum e_bool
{
	FALSE_E = 0,
	TRUE_E = 1
}	t_bool;

typedef enum e_state
{
	FORK_E = 0,
	EATING_E = 1,
	SLEEPING_E = 2,
	THINKING_E = 3,
	DIED_E = 4,
	FINISH_E = 5
}	t_state;

typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timeval;
typedef struct s_table	t_table;

typedef struct s_philo
{
	int			philo_id;
	pthread_t	thread_id;
	int			eat_count;
	int			finish;
	t_timeval	last_eat;
	t_table		*table;
}				t_philo;

typedef struct s_table
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat_count;
	int			count_finish;
	int			flag;
	t_philo		*philo;
	t_mutex		*fork_mutex;
	t_mutex		print_mutex;
	t_mutex		exit_mutex;
	t_mutex		philo_mutex;
	t_mutex		state_mutex;
	t_mutex		eat_count_mutex;
	pthread_t	check;
	t_timeval	start;
	t_timeval	check_time;
	int			curr_time;
}				t_table;

/* ===== utils ===== */
void	all_free(void *ptr1, void *ptr2);
ssize_t	ft_atoi(const char *str);
char	*ft_strdup(char *str);
t_bool	ft_isdigit(char num);
t_bool	start_philo(t_table *table);
void	*philo_to_job(void *arg);
void	thread_pause(int ms);
void	detach(t_table *table);
void	destroy_mutex(t_table *table);

/* ===== error ===== */
int		error_print(char *str);

/* ===== state modularity ===== */
t_bool	state_print(t_philo *philo, t_table *table, t_state state);

/* ===== action modularity ===== */
t_bool	action_get_fork(t_philo *philo, t_table *table);
void	action_put_fork(t_philo *philo, t_table *table);
t_bool	action_eat(t_philo *philo, t_table *table);
t_bool	action_sleep(t_philo *philo, t_table *table);

/* ===== time modularity ===== */
int		sleep_time_diff(t_timeval *start);
int		check_time_diff(t_philo *philo, t_timeval *time);
int		print_time_diff(t_table *table);

/* ===== check modularity ===== */
t_bool	check_arg(int argc, char **argv);
void	*check_philo(void *arg);

/* ===== set modularity ===== */
void	set_table(int argc, char **argv, t_table *table);
t_bool	set_philo(t_table *table);
void	set_mutex(t_table *table);

#endif
