/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:06:49 by dimioui           #+#    #+#             */
/*   Updated: 2022/02/10 12:37:59 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

pthread_mutex_t	mutex;
int	n = 0;

void	*routine()
{
	int	i;

	i = 0;
	while (i < 1000000)
	{
		pthread_mutex_lock(&mutex);
		n++;
		pthread_mutex_unlock(&mutex);
		i++;
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	pthread_t	philos[4];
	int			i;

	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < 4)
	{
		if (pthread_create(&philos[i], NULL, &routine, NULL) != 0)
		{
			printf("Failed to create thread.\n");
			return (1);
		}
		printf("Thread %d has started\n", i);
		if (pthread_join(philos[i], NULL) != 0)
			return (2);
		printf("Thread %d has finished execution\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf("n = %d\n", n);
	return (0);
}
