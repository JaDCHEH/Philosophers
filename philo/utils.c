/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:54:33 by cjad              #+#    #+#             */
/*   Updated: 2022/03/26 17:00:56 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, t_rules *rules, char	*str)
{
	int	i;

	i = get_time() - philo->start_time;
	pthread_mutex_lock(&rules->mulock);
	if (rules->philo_alive && !rules->all_ate)
		printf("%d %d %s \n", i, philo->philo_id, str);
	pthread_mutex_unlock(&rules->mulock);
}

int	find_max(t_philo *philo)
{
	if (philo->l_fork > philo->r_fork)
		return (philo->l_fork);
	else
		return (philo->r_fork);
}

int	find_min(t_philo *philo)
{
	if (philo->l_fork < philo->r_fork)
		return (philo->l_fork);
	else
		return (philo->r_fork);
}

void	philo_do(t_philo *philo, t_rules *rules, int r, char *str)
{
	print_action(philo, rules, str);
	if (rules->nbr_of_philo <= 20)
		ft_usleep(r, 10);
	else
		usleep(r * 1000);
}

int	get_time(void)
{
	struct timeval	a;

	gettimeofday(&a, NULL);
	return (a.tv_sec * 1000 + a.tv_usec / 1000);
}
