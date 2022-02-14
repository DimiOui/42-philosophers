/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:07:12 by dimioui           #+#    #+#             */
/*   Updated: 2022/02/14 15:38:02 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdint.h>

# define MAX_PHILO 200

struct s_data;
typedef struct s_philos {
	int					id;
	int					ate;
	int					left_fork;
	int					right_fork;
	int					time_eat;
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
	int					all_ate;
	int					time_birth;
	pthread_mutex_t		fork_mutex[MAX_PHILO];
	pthread_mutex_t		eat_mutex;
	pthread_mutex_t		action_mutex;
	t_philos			philos[MAX_PHILO];
}	t_data;

void	error(int error);
int		parse_all(t_data *data, char **av);
int		init_mutex(t_data *data);
int		init_philos(t_data *data);
int		ft_atoi(const char *str);
int		init_routine(t_data *data);
void	dead_check(t_data *data, t_philos *philo);
void	destroy_philos(t_data *data, t_philos *philo);
void	*routine(void *void_philo);
void	philo_eats(t_philos *philo);
void	philo_does(t_data *data, int id, char *str);
void	s_sleep(int time, t_data *data);
int		m_time(int past, int pres);
int		timestamp(void);

#endif
