/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmathis <dmathis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 00:02:34 by dmathis           #+#    #+#             */
/*   Updated: 2024/09/10 13:08:14 by dmathis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long time)
{
	long long	start;
	long long	now;

	start = get_current_time();
	while (1)
	{
		now = get_current_time();
		if (now - start >= time)
			break ;
		usleep(50);
	}
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error with current time\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_print_action(t_philo philo, char c)
{
	pthread_mutex_lock(&philo.data->dead_lock);
	if (c == 'd' && philo.data->wrotedead == 0)
	{
		printf("%zu ", (get_current_time() - philo.data->start_time));
		printf("%d died\n", philo.id + 1);
		philo.data->wrotedead = 1;
	}
	if (c != 'd' && philo.data->dead_flag == 0)
	{
		printf("%zu ", (get_current_time() - philo.data->start_time));
		if (c == 'f')
			printf("%d has taken a fork\n", philo.id + 1);
		if (c == 'e')
			printf("%d is eating\n", philo.id + 1);
		if (c == 't')
			printf("%d is thinking\n", philo.id + 1);
		if (c == 's')
			printf("%d is sleeping\n", philo.id + 1);
	}
	pthread_mutex_unlock(&philo.data->dead_lock);
}
