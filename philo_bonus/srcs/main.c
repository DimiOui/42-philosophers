/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:46:18 by dimioui           #+#    #+#             */
/*   Updated: 2022/02/15 11:21:25 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		parse_ret;

	if (ac != 5 && ac != 6)
		error (1);
	parse_ret = parse_all(&data, av);
	if (!(parse_ret))
		error (2);
	if (!(init_routine(&data)))
		error (3);
	return (0);
}
