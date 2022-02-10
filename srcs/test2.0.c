/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:06:49 by dimioui           #+#    #+#             */
/*   Updated: 2022/02/10 15:16:21 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

void	*roll_dice()
{
	int	i = 0;
	int	*result;
	int	value = (rand() % 6) + 1;
	result = malloc(sizeof(int));
	*result = value;
	return (void*)result;
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	pthread_t		dicerolls[10];
	int				*res;
	int				i;
	pthread_mutex_t	mutex;

	srand(time(NULL));
	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < 10)
	{
		if (pthread_create(&dicerolls[i], NULL, &roll_dice, NULL) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (pthread_join(dicerolls[i], (void **)&res) != 0)
			return (2);
		printf("Result : %d\n", *res);
		free(res);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	return (0);
}

// Je crois que le mutex ne sert à rien ici, il faut que je revoie
// les premieres videos de CodeVault.
