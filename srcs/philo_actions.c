/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:25:14 by dimioui           #+#    #+#             */
/*   Updated: 2022/02/15 11:23:05 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eats(t_philos *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->fork_mutex[philo->left_fork]);
	philo_does(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&data->fork_mutex[philo->right_fork]);
	philo_does(data, philo->id, "has taken a fork");
	pthread_mutex_lock(&data->eat_mutex);
	philo_does(data, philo->id, "is eating");
	philo->time_eat = timestamp();
	pthread_mutex_unlock(&data->eat_mutex);
	s_sleep(data->time_to_eat, data);
	(philo->ate)++;
	pthread_mutex_unlock(&data->fork_mutex[philo->left_fork]);
	pthread_mutex_unlock(&data->fork_mutex[philo->right_fork]);
}

void	*routine(void *void_philo)
{
	t_philos	*philo;
	t_data		*data;

	philo = (struct s_philos *)void_philo;
	data = philo->data;
	if (philo->id % 2)
		usleep(20000);
	while (!(data->dead))
	{
		philo_eats(philo);
		if (data->all_ate)
			break ;
		philo_does(data, philo->id, "is sleeping");
		s_sleep(data->time_to_sleep, data);
		philo_does(data, philo->id, "is thinking");
	}
	return (NULL);
}

void	destroy_philos(t_data *data, t_philos *philo)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		pthread_join(philo[i].philo_thread, NULL);
	i = -1;
	while (++i < data->nb_philos)
		pthread_mutex_destroy(&data->fork_mutex[i]);
	pthread_mutex_destroy(&data->action_mutex);
}

void	dead_check(t_data *data, t_philos *philo)
{
	int	i;

	while (!(data->all_ate))
	{
		i = -1;
		while (++i < data->nb_philos && !(data->dead))
		{
			pthread_mutex_lock(&data->eat_mutex);
			if (m_time(philo[i].time_eat, timestamp()) > data->time_to_die)
			{
				philo_does(data, i, "died");
				data->dead = 1;
			}
			pthread_mutex_unlock(&data->eat_mutex);
			usleep(200);
		}
		if (data->dead)
			break ;
		i = 0;
		while ((data->nb_must_eat != -1) && (i < data->nb_philos
				&& philo[i].ate >= data->nb_must_eat))
			i++;
		if (i == data->nb_philos)
			data->all_ate = 1;
	}
}

int	init_routine(t_data *data)
{
	int			i;
	t_philos	*philo;

	i = 0;
	philo = data->philos;
	data->time_birth = timestamp();
	while (i < data->nb_philos)
	{
		if (pthread_create(&philo[i].philo_thread, NULL, routine, &philo[i]))
			return (false);
		philo[i].time_eat = timestamp();
		i++;
	}
	dead_check(data, data->philos);
	destroy_philos(data, philo);
	return (true);
}

/* ************************************************************************** */
/* Now that we parsed everything, and our structs are filled, we create a     */
/* thread for each different philosophers and sends them the routine          */
/* We initialize our timestamp at the moment the thread is created.           */
/* At the end of the loop, we check if any philosopher is dead, then we       */
/* destroy all the threads created to avoid leaks and such.                   */
/* ************************************************************************** */
