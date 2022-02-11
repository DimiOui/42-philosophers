/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:07:12 by dimioui           #+#    #+#             */
/*   Updated: 2022/02/11 16:07:07 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

# define MAX_PHILO 200

typedef struct s_philos {
	int					id;
	int					ate;
	int					left_fork;
	int					right_fork;
	pthread_t			philo_thread;
	struct s_data		*data;
}	t_philos;

typedef struct s_data {
	int					nb_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_must_eat;
	int					dead;
	long long			time_born;
	long long			time_eat;
	pthread_mutex_t		fork_mutex[MAX_PHILO];
	pthread_mutex_t		eat_mutex;
	t_philos			philos[MAX_PHILO];
}	t_data;

void	error(int error);
int		parse_all(t_data *data, char **av);
int		parse_mutex(t_data *data);
int		parse_philos(t_data *data);
int		ft_atoi(const char *str);

#endif
