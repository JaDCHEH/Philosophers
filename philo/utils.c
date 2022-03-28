/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:54:33 by cjad              #+#    #+#             */
/*   Updated: 2022/03/28 18:43:47 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char	*str)
{
	int	i;

	i = get_time() - philo->start_time;
	printf("%d %d %s \n", i, philo->philo_id, str);
}

void	philo_do(t_philo *philo, t_rules *rules, int r, char *str)
{
	pthread_mutex_lock(&rules->end_lock);
	if (rules->philo_alive && rules->all_ate == 0)
	{
		print_action(philo, str);
		pthread_mutex_unlock(&rules->end_lock);
		if (rules->nbr_of_philo <= 20 && r)
			ft_usleep(r, 10);
		else if (r)
			usleep(r * 1000);
	}
	else
		pthread_mutex_unlock(&rules->end_lock);
}

int	get_time(void)
{
	struct timeval	a;

	gettimeofday(&a, NULL);
	return (a.tv_sec * 1000 + a.tv_usec / 1000);
}
