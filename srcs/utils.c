/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:07:01 by dimioui           #+#    #+#             */
/*   Updated: 2022/02/14 15:58:47 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		{
			if (str[i] == '-')
				sign *= (-1);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + t.tv_usec / 1000);
}

int	m_time(int past, int pres)
{
	return (pres - past);
}

void	s_sleep(int time, t_data *data)
{
	int	i;

	i = timestamp();
	while (!(data->dead))
	{
		if (m_time(i, timestamp()) >= time)
			break;
		usleep(150);
	}
}

void	philo_does(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&data->action_mutex);
	if (!(data->dead))
	{
		printf("%i\t ", timestamp() - data->time_birth);
		printf("%i ", id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&data->action_mutex);
	return ;
}
