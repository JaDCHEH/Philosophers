/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:54:13 by cjad              #+#    #+#             */
/*   Updated: 2022/03/27 15:58:38 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char	**av)
{
	t_rules	rules;

	if (ac == 5)
		philosophers(&rules, av, 0);
	else if (ac == 6)
		philosophers(&rules, av, 1);
	else
		printf("Error\nInvalid number of arguments.\n");
}
