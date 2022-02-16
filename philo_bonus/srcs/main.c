/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:46:18 by dimioui           #+#    #+#             */
/*   Updated: 2022/02/16 18:20:04 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (error(1), false);
	if (!(parse_all(&data, av)))
		return (error(2), false);
	if (!(init_routine(&data)))
		return (error(3), false);
	return (true);
}
