/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:25:14 by dimioui           #+#    #+#             */
/*   Updated: 2022/02/16 15:28:19 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eats(t_philos *philo)
{
	t_data	*data;

	data = philo->data;
	if (data->nb_philos == 1)
		philo_one(philo);
	else
	{
		sem_wait(data->forks);
		philo_does(data, philo->id, "has taken a fork");
		sem_wait(data->forks);
		philo_does(data, philo->id, "has taken a fork");
		sem_wait(data->eat);
		philo_does(data, philo->id, "is eating");
		philo->time_eat = timestamp();
		sem_post(data->eat);
		s_sleep(data->time_to_eat, data);
		(philo->ate)++;
		sem_post(data->forks);
		sem_post(data->forks);
	}
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
	sem_close(data->forks);
	sem_close(data->action);
	sem_close(data->eat);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_action");
	sem_unlink("/philo_eat");
}

void	dead_check(t_data *data, t_philos *philo)
{
	int	i;

	while (!(data->all_ate))
	{
		i = -1;
		while (++i < data->nb_philos && !(data->dead))
		{
			sem_wait(data->eat);
			if (m_time(philo[i].time_eat, timestamp()) > data->time_to_die)
			{
				philo_does(data, i, "died");
				data->dead = 1;
			}
			sem_post(data->eat);
			usleep(1000);
		}
		if (data->dead)
			break ;
		i = 0;
		while ((data->nb_must_eat != -1) && (i < data->nb_philos)
			&& (philo[i].ate >= data->nb_must_eat))
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
		if (pthread_create(&philo[i].philo_thread, NULL, &routine, &philo[i]))
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
