/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimioui <dimioui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:46:18 by dimioui           #+#    #+#             */
/*   Updated: 2022/02/11 15:07:02 by dimioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		parse_ret;

	if (ac != 5 && ac != 6)
		error (1);
	if ((parse_ret = parse_all(&data, av)))
		error (2);
	return (0);
}
