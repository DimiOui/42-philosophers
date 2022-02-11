/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:56:01 by dimioui           #+#    #+#             */
/*   Updated: 2022/02/11 15:38:59 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_philos(t_data *data)
{
	int	i;

	i = data->nb_philos;
	while (--i >= 0)
	{
		data->philos[i].id = i;
		printf("philo number : %d ", data->philos[i].id);
		data->philos[i].ate = 0;
		data->philos[i].left_fork = i;
		printf(" with fork left number %d ", data->philos[i].left_fork);
		data->philos[i].right_fork = (i + 1) % data->nb_philos;
		printf("and right fork number %d\n", data->philos[i].right_fork);
		data->philos[i].data = data;
	}
	return (0);
}

int	parse_mutex(t_data *data)
{
	int	i;

	i = data->nb_philos;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&data->fork_mutex[i], NULL))
			return (1);
		printf("mutex fork initialized\n");
	}
	return (0);
}

int	parse_all(t_data *data, char **av)
{
	data->nb_philos = ft_atoi(av[1]);
	printf("data nb philos : %d\n", data->nb_philos);
	data->time_to_die = ft_atoi(av[2]);
	printf("data ttdie : %d\n", data->time_to_die);
	data->time_to_eat = ft_atoi(av[3]);
	printf("data tteat : %d\n", data->time_to_eat);
	data->time_to_sleep = ft_atoi(av[4]);
	printf("data ttsleep: %d\n", data->time_to_sleep);
	data->died = 0;
	if (data->nb_philos < 2 || data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0)
		return (1);
	if (av[5])
	{
		data->nb_must_eat = ft_atoi(av[5]);
		if (data->nb_must_eat <= 0)
			return (1);
	}
	else
		data->nb_must_eat = -1;
	if (parse_mutex(data))
		return (1);
	if (parse_philos(data))
		return (1);
	return (0);
}
