/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:45:02 by cjad              #+#    #+#             */
/*   Updated: 2022/03/28 18:45:28 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(t_rules *rules)
{
	int	i;

	pthread_mutex_lock(&rules->mulock);
	i = rules->counter;
	pthread_mutex_lock(&rules->end_lock);
	rules->philo[i].start_time = get_time();
	pthread_mutex_unlock(&rules->mulock);
	while (rules->philo_alive && rules->all_ate == 0)
	{
		pthread_mutex_unlock(&rules->end_lock);
		philo_eat(rules, &rules->philo[i]);
		if (rules->nbr_of_philo == 1)
			break ;
		philo_do(&rules->philo[i], rules, rules->time_to_sleep, "is sleeping");
		philo_do(&rules->philo[i], rules, 0, "is thinking");
		pthread_mutex_lock(&rules->end_lock);
	}
	pthread_mutex_unlock(&rules->end_lock);
}

void	death_c(t_rules *rules)
{
	int	i;

	while (rules->nbr_of_philo && rules->philo_alive && !rules->all_ate)
	{
		i = 0;
		while (i < rules->nbr_of_philo)
		{
			death_check(&rules->philo[i], rules);
			i++;
		}
		if (meal_check(rules))
		{
			pthread_mutex_lock(&rules->end_lock);
			printf("All philosophers ate %d times.\n", rules->nbr_of_eat);
			rules->all_ate = 1;
			pthread_mutex_unlock(&rules->end_lock);
		}
	}
}

int	create_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nbr_of_philo)
	{
		if (pthread_create(&rules->philo[i].phil, NULL, (void *)routine, rules))
			return (1);
		usleep(50);
		pthread_mutex_lock(&rules->mulock);
		rules->counter++;
		pthread_mutex_unlock(&rules->mulock);
		i++;
	}
	if (pthread_create(&rules->death, NULL, (void *)death_c, rules))
		return (1);
	join_threads(rules);
	return (0);
}

int	join_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nbr_of_philo)
	{
		if (pthread_join(rules->philo[i].phil, NULL))
			return (1);
		pthread_mutex_lock(&rules->mulock);
		i++;
		pthread_mutex_unlock(&rules->mulock);
	}
	if (pthread_join(rules->death, NULL))
		return (1);
	destroy_mutex(rules);
	return (0);
}
