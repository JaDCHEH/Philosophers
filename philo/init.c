/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:54:03 by cjad              #+#    #+#             */
/*   Updated: 2022/03/28 18:41:42 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nbr_of_philo)
	{
		rules->philo[i].philo_id = i + 1;
		rules->philo[i].l_fork = i % rules->nbr_of_philo;
		rules->philo[i].r_fork = (i + 1) % rules->nbr_of_philo;
		rules->philo[i].philo_n_eat = 0;
		rules->philo->start_time = 0;
		rules->philo[i].lst_meal = 0;
		i++;
	}
	return (0);
}

void	init_2(t_rules *rules, char **av)
{
	rules->nbr_of_philo = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	rules->philo_alive = 1;
	rules->counter = 0;
	rules->death_counter = 0;
	rules->all_ate = 0;
}

int	init_1(t_rules *rules, char **av, int j)
{
	init_2(rules, av);
	if (rules->nbr_of_philo < 0 || rules->time_to_die < 0
		|| rules->time_to_eat < 0 || rules->time_to_sleep < 0)
	{
		printf("Error\nArgument is negative\n");
		return (-1);
	}
	if (j)
	{
		rules->nbr_of_eat = ft_atoi(av[5]);
		if (rules->nbr_of_eat < 0)
		{
			printf("Error\nArgument is negative\n");
			return (-1);
		}
	}
	else
		rules->nbr_of_eat = -1;
	return (0);
}

int	philosophers(t_rules *rules, char **av, int j)
{
	int	i;

	i = 0;
	if (init_1(rules, av, j))
		return (1);
	rules->philo = malloc (sizeof(t_philo) * rules->nbr_of_philo);
	rules->forks = malloc (sizeof(pthread_mutex_t) * rules->nbr_of_philo);
	if (!rules->philo || !rules->forks)
		return (1);
	while (i < rules->nbr_of_philo)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&rules->mulock, NULL);
	pthread_mutex_init(&rules->end_lock, NULL);
	if (init_philo(rules))
		return (1);
	if (create_threads(rules))
		return (1);
	return (0);
}
