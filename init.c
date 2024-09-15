/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:05:32 by dmathis           #+#    #+#             */
/*   Updated: 2024/09/10 13:07:59 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (-1);
		i++;
	}
	if (pthread_mutex_init(&(data->write_lock), NULL))
		return (-1);
	if (pthread_mutex_init(&(data->meal_lock), NULL))
		return (-1);
	if (pthread_mutex_init(&(data->dead_lock), NULL))
		return (-1);
	return (0);
}

int	init(t_data *data, char **argv)
{
	parse_the_args(data, argv);
	data->dead_flag = 0;
	data->full_counter = 0;
	if (data->philo_nb <= 0 || data->philo_nb > 200)
		return (printf("Philo number has to from 1 to 200 included"), -1);
	if (data->time_to_die < 100 || data->time_to_eat < 100
		|| data->time_to_sleep < 100)
		return (printf("Time values must be at least 100 ms"), -1);
	if (argv[5] && data->meals_limit < 0)
		return (printf("What could we do with a negative number of meals ?"),
			-1);
	if (init_mutex(data) == -1)
		return (-1);
	init_philo(data);
	return (0);
}

void	parse_the_args(t_data *data, char **argv)
{
	data->philo_nb = ft_atoi(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		data->meals_limit = ft_atoi(argv[5]);
	else
		data->meals_limit = -1;
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		data->philos[i].id = i;
		data->philos[i].meals_counter = 0;
		data->wrotedead = 0;
		data->philos[i].left_fork_id = i;
		data->philos[i].right_fork_id = (i + 1) % data->philo_nb;
		data->philos[i].last_meal = get_current_time();
		data->philos[i].data = data;
		data->philos[i].time_to_die = data->time_to_die;
		data->philos[i].time_to_eat = data->time_to_eat;
		data->philos[i].time_to_sleep = data->time_to_sleep;
		i++;
	}
}
