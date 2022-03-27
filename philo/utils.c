/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:54:33 by cjad              #+#    #+#             */
/*   Updated: 2022/03/27 19:28:57 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, t_rules *rules, char	*str)
{
	int	i;

	i = get_time() - philo->start_time;
	if (rules->philo_alive && !rules->all_ate)
		printf("%d %d %s \n", i, philo->philo_id, str);
}

void	philo_do(t_philo *philo, t_rules *rules, int r, char *str)
{
	if(rules->philo_alive && !rules->all_ate)
	{
		pthread_mutex_lock(&rules->mulock);
		print_action(philo, rules, str);
		pthread_mutex_unlock(&rules->mulock);
		if (rules->nbr_of_philo <= 20)
			ft_usleep(r, 10);
		else
			usleep(r * 1000);
	}
}

int	get_time(void)
{
	struct timeval	a;

	gettimeofday(&a, NULL);
	return (a.tv_sec * 1000 + a.tv_usec / 1000);
}
