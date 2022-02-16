/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:56:01 by dimioui           #+#    #+#             */
/*   Updated: 2022/02/16 11:11:53 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_data *data)
{
	int	i;

	i = data->nb_philos;
	while (--i >= 0)
	{
		data->philos[i].id = i;
		data->philos[i].ate = 0;
		data->philos[i].left_fork = i;
		data->philos[i].right_fork = (i + 1) % data->nb_philos;
		data->philos[i].time_eat = 0;
		data->philos[i].data = data;
	}
	return (true);
}

/* ************************************************************************** */
/* initialize all our data in our data structure.                             */
/* ************************************************************************** */

int	init_mutex(t_data *data)
{
	int	i;

	i = data->nb_philos;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&data->fork_mutex[i], NULL) != 0)
			return (false);
	}
	if (pthread_mutex_init(&data->action_mutex, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->eat_mutex, NULL) != 0)
		return (false);
	return (true);
}

/* ************************************************************************** */
/* the parse_mutex function that initializes all the mutexes in our structs   */
/* so we can use them after in our philo_actions functions                    */
/* ************************************************************************** */

int	parse_all(t_data *data, char **av)
{
	data->nb_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->dead = 0;
	data->all_ate = 0;
	if (data->nb_philos < 1 || data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0 || data->nb_philos > MAX_PHILO)
		return (false);
	if (av[5])
	{
		data->nb_must_eat = ft_atoi(av[5]);
		if (data->nb_must_eat <= 0)
			return (false);
	}
	else
		data->nb_must_eat = -1;
	if (!init_mutex(data))
		return (false);
	if (!init_philos(data))
		return (false);
	return (true);
}

/* ************************************************************************** */
/* parse all fills our structs with our program parameters at first           */
/* with our 2 structures, data and philos which contains all the informations */
/* Basically we just initialize mutexes and structures                        */
/* ************************************************************************** */
