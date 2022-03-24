#include "philo.h"

void	init_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nbr_of_philo)
	{
		rules->philo[i].philo_id = i + 1;
		rules->philo[i].l_fork = i % rules->nbr_of_philo;
		rules->philo[i].r_fork = (i + 1) % rules->nbr_of_philo;
		rules->philo[i].philo_n_eat = 0;
		rules->philo[i].lst_meal = 0;
		rules->philo[i].phil = malloc (sizeof(pthread_t));
		i++;
	}
	i = 0;
}

void	parse_arguments(t_rules *rules, char **av, int j)
{
	int	i;

	i = 0;
	rules->nbr_of_philo = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	rules->counter = 0;
	if (j)
		rules->nbr_of_eat = ft_atoi(av[5]);
	else
		rules->nbr_of_eat = -1;
	rules->philo = (t_philo *) malloc (sizeof(t_philo) * rules->nbr_of_philo);
	rules->forks = (pthread_mutex_t *) malloc (sizeof(pthread_mutex_t) * rules->nbr_of_philo);
	while (i < rules->nbr_of_philo)
	{
		pthread_mutex_init(&rules->forks[i],NULL);
		i++;
	}
	pthread_mutex_init(&rules->mulock,NULL);
	init_philo(rules);
	creat_threads(rules);
}