/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:53:52 by cjad              #+#    #+#             */
/*   Updated: 2022/03/28 18:45:53 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks_eat(t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(&rules->forks[philo->r_fork]);
	philo_do(philo, rules, 0, "has taken a fork");
	pthread_mutex_lock(&rules->end_lock);
	philo->lst_meal = get_time() - philo->start_time;
	pthread_mutex_unlock(&rules->end_lock);
	philo_do(philo, rules, 0, "is eating");
	pthread_mutex_lock(&rules->mulock);
	philo->philo_n_eat++;
	pthread_mutex_unlock(&rules->mulock);
}

void	philo_eat(t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(&rules->forks[philo->l_fork]);
	philo_do(philo, rules, 0, "has taken a fork");
	if (rules->nbr_of_philo > 1)
	{
		taking_forks_eat(rules, philo);
		pthread_mutex_lock(&rules->end_lock);
		if (rules->philo_alive && rules->all_ate == 0)
		{
			pthread_mutex_unlock(&rules->end_lock);
			if (rules->nbr_of_philo <= 20)
				ft_usleep(rules->time_to_eat, 10);
			else
				usleep(rules->time_to_eat * 1000);
		}
		else
			pthread_mutex_unlock(&rules->end_lock);
		pthread_mutex_unlock(&rules->forks[philo->r_fork]);
		pthread_mutex_unlock(&rules->forks[philo->l_fork]);
	}
}

void	death_check(t_philo *philo, t_rules *rules)
{
	int	i;

	pthread_mutex_lock(&rules->end_lock);
	i = get_time() - philo->start_time - philo->lst_meal;
	pthread_mutex_unlock(&rules->end_lock);
	if (i >= rules->time_to_die)
	{
		philo_do(philo, rules, 0, "has died");
		pthread_mutex_lock(&rules->end_lock);
		rules->philo_alive = 0;
		pthread_mutex_unlock(&rules->end_lock);
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
