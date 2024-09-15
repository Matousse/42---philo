/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:34:35 by dmathis           #+#    #+#             */
/*   Updated: 2024/09/15 14:07:31 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

struct s_philo
{
	int				id;
	long			meals_counter;
	unsigned long	last_meal;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				left_fork_id;
	int				right_fork_id;
	pthread_t		thread_id;
	pthread_t		dead_monitor_id;
	t_data			*data;
};

struct	s_data
{
	int				philo_nb;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals_limit;
	size_t			start_time;
	int				dead_flag;
	int				full_counter;
	int				wrotedead;
	pthread_mutex_t	forks[300];
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	t_philo			philos[300];
};

void	ft_eat(t_philo *philo);
void	ft_eat2(t_philo *philo);
void	ft_eat3(t_philo *philo);
void	parse_the_args(t_data *data, char **argv);
void	init_philo(t_data *data);
void	*routine(void *philos);
void	ft_print_action(t_philo philo, char c);
size_t	get_current_time(void);
void	join_all_and_clean_exit(t_philo *philos);
int		init(t_data *data, char **argv);
void	ft_usleep(long time);

#endif
