/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:54:42 by cjad              #+#    #+#             */
/*   Updated: 2022/03/26 16:54:43 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int num, int a)
{
	int	start;
	int	current;

	start = get_time() + num;
	current = get_time();
	while (start > current)
	{
		current = get_time();
		usleep(10);
	}
}
