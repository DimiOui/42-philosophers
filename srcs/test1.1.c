/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:06:49 by dimioui           #+#    #+#             */
/*   Updated: 2022/02/10 16:40:03 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_data {
	int				n;
	pthread_mutex_t	mutex;
}					t_data;

void	*routine(void *data)
{
	struct s_data	*ctx;
	int				i;

	ctx = (struct s_data *)data;
	i = 0;
	ctx->n = 0;
	while (i < 1000000)
	{
		pthread_mutex_lock(&ctx->mutex);
		ctx->n++;
		pthread_mutex_unlock(&ctx->mutex);
		i++;
	}
}

int	main(int ac, char **av, t_data *ctx)
{
	pthread_t	philos[4];
	int			i;

	(void)ac;
	(void)av;
	pthread_mutex_init(&ctx->mutex, NULL);
	i = 0;
	while (i < 4)
	{
		if (pthread_create(&philos[i], NULL, &routine, (void *)&ctx->mutex) != 0)
			return (1);
		printf("Thread %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(philos[i], NULL) != 0)
			return (2);
		printf("Thread %d has finished execution\n", i);
		i++;
	}
	pthread_mutex_destroy(&ctx->mutex);
	printf("n = %d\n", ctx->n);
	return (0);
}
