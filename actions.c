/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:40:09 by dmathis           #+#    #+#             */
/*   Updated: 2024/09/10 10:50:56 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&(philo->data->forks[philo->left_fork_id]));
	else
		pthread_mutex_lock(&(philo->data->forks[philo->right_fork_id]));
	pthread_mutex_lock(&philo->data->write_lock);
	ft_print_action(*philo, 'f');
	pthread_mutex_unlock(&philo->data->write_lock);
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&(philo->data->forks[philo->right_fork_id]));
	else
		pthread_mutex_lock(&(philo->data->forks[philo->left_fork_id]));
	ft_eat2(philo);
}

void	ft_eat2(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write_lock);
	ft_print_action(*philo, 'f');
	pthread_mutex_unlock(&philo->data->write_lock);
	pthread_mutex_lock(&philo->data->write_lock);
	ft_print_action(*philo, 'e');
	pthread_mutex_unlock(&philo->data->write_lock);
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_counter++;
	pthread_mutex_unlock(&philo->data->meal_lock);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(&(philo->data->forks[philo->right_fork_id]));
	pthread_mutex_unlock(&(philo->data->forks[philo->left_fork_id]));
	ft_eat3(philo);
}

void	ft_eat3(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write_lock);
	ft_print_action(*philo, 's');
	pthread_mutex_unlock(&philo->data->write_lock);
	ft_usleep(philo->data->time_to_sleep);
	pthread_mutex_lock(&philo->data->write_lock);
	ft_print_action(*philo, 't');
	pthread_mutex_unlock(&philo->data->write_lock);
}
