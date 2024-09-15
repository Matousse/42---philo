/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:09:47 by dmathis           #+#    #+#             */
/*   Updated: 2024/09/10 12:08:34 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
// gerer le cas ou il ny a qun philosopher

#include "philo.h"

void	*check_if_dead(void *philos)
{
	t_philo	*philo;
	long	time_would_die;

	philo = (t_philo *)philos;
	ft_usleep(philo->data->time_to_die + 1);
	pthread_mutex_lock(&philo->data->meal_lock);
	time_would_die = (get_current_time() - philo->last_meal);
	pthread_mutex_unlock(&philo->data->meal_lock);
	if (time_would_die >= philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->write_lock);
		ft_print_action(*philo, 'd');
		pthread_mutex_unlock(&philo->data->write_lock);
		pthread_mutex_lock(&philo->data->dead_lock);
		philo->data->dead_flag = 1;
		pthread_mutex_unlock(&philo->data->dead_lock);
		return (NULL);
	}
	return (NULL);
}

void	join_all_and_clean_exit(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->philo_nb)
	{
		if (pthread_join(philos[i].thread_id, NULL))
			printf("Error\n Thread did not join\n");
		i++;
	}
	i = 0;
	pthread_mutex_lock(&(philos->data->meal_lock));
	while (i < (philos[0]).data->philo_nb - 1)
	{
		pthread_mutex_destroy(&philos[0].data->forks[i]);
		i++;
	}
	pthread_mutex_unlock(&(philos->data->meal_lock));
	pthread_mutex_destroy(&(philos[0]).data->write_lock);
	pthread_mutex_destroy(&(philos[0]).data->meal_lock);
	pthread_mutex_destroy(&(philos[0]).data->dead_lock);
}

void	*routine(void *philosophers)
{
	t_philo	*philo;

	philo = (t_philo *)philosophers;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2);
	pthread_create(&philo->dead_monitor_id, NULL, check_if_dead, philosophers);
	pthread_mutex_lock(&philo->data->dead_lock);
	while (!philo->data->dead_flag)
	{
		pthread_mutex_unlock(&philo->data->dead_lock);
		ft_eat(philo);
		if (philo->meals_counter == philo->data->meals_limit)
		{
			pthread_mutex_lock(&philo->data->dead_lock);
			philo->data->full_counter++;
			break ;
		}
		pthread_mutex_lock(&philo->data->dead_lock);
	}
	pthread_mutex_unlock(&philo->data->dead_lock);
	pthread_join(philo->dead_monitor_id, NULL);
	return (NULL);
}

int	start(t_data *data)
{
	int	i;
	int	philo_tot;

	philo_tot = data->philo_nb;
	i = -1;
	data->start_time = get_current_time();
	if (philo_tot == 1)
		return (printf("%lu 1 has taken a fork\n%lu 1 died\n",
				data->time_to_die, data->time_to_die), -1);
	while (++i < philo_tot)
		data->philos[i].last_meal = get_current_time();
	i = 0;
	while (i < philo_tot)
	{
		if (pthread_create(&(data->philos[i].thread_id), NULL, routine,
				&(data->philos[i])))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		solo;

	i = 0;
	if (argc != 5 && argc != 6)
		return (1);
	if (init(&data, argv) == -1)
		return (-1);
	solo = start(&data);
	if (solo == 1)
		return (printf("Error with the threads"), -1);
	if (solo == -1)
		return (0);
	join_all_and_clean_exit(data.philos);
	return (0);
}
