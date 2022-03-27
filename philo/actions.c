/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:53:52 by cjad              #+#    #+#             */
/*   Updated: 2022/03/27 18:41:54 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(&rules->forks[philo->l_fork]);
	print_action(philo, rules, "has taken a fork");
	if (rules->nbr_of_philo > 1)
	{
		pthread_mutex_lock(&rules->forks[philo->r_fork]);
		print_action(philo, rules, "has taken a fork");
		philo->lst_meal = get_time() - philo->start_time;
		print_action(philo, rules, "is eating");
		pthread_mutex_lock(&rules->mulock);
		philo->philo_n_eat++;
		pthread_mutex_unlock(&rules->mulock);
		if (rules->nbr_of_philo <= 20)
			ft_usleep(rules->time_to_eat, 10);
		else
			usleep(rules->time_to_eat * 1000);
		pthread_mutex_unlock(&rules->forks[philo->r_fork]);
		pthread_mutex_unlock(&rules->forks[philo->l_fork]);
	}
}

void	death_check(t_philo *philo, t_rules *rules)
{
	int	i;

	i = get_time() - philo->start_time - philo->lst_meal;
	if (i >= rules->time_to_die)
	{
		print_action(philo, rules, "has died");
		pthread_mutex_lock(&rules->mulock);
		rules->philo_alive = 0;
		pthread_mutex_unlock(&rules->mulock);
	}
}

int	meal_check(t_rules *rules)
{
	int	i;

	i = 0;
	if (rules->nbr_of_eat >= 0)
	{
		pthread_mutex_lock(&rules->mulock);
		while (i < rules->nbr_of_philo)
		{
			if (rules->philo[i].philo_n_eat < rules->nbr_of_eat)
			{
				pthread_mutex_unlock(&rules->mulock);
				return (0);
			}
			i++;
		}
		pthread_mutex_unlock(&rules->mulock);
		return (1);
	}
	return (0);
}
