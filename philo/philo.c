#include "philo.h"

void	*routine(t_rules *rules)
{
	int	i;

	i = rules->counter;
	rules->philo[i].start_time = get_time();
	while (1)
	{
		pthread_mutex_lock(&rules->forks[find_max(&rules->philo[i])]);
		pthread_mutex_lock(&rules->forks[find_min(&rules->philo[i])]);
		print_action(&rules->philo[i], "has taken a fork");
		print_action(&rules->philo[i], "has taken a fork");
		philo_do(&rules->philo[i], rules->time_to_eat, "is eating");
		pthread_mutex_unlock(&rules->forks[rules->philo[i].l_fork]);
		pthread_mutex_unlock(&rules->forks[rules->philo[i].r_fork]);
		philo_do(&rules->philo[i], rules->time_to_sleep, "is sleeping");
		print_action(&rules->philo[i], "is thinking");
	}
}

void	creat_threads(t_rules *rules)
{
	int	i;
	
	i = 0;
	while (i < rules->nbr_of_philo)
	{
		pthread_create(&rules->philo[i].phil, NULL, (void *)routine, rules);
		usleep(50);
		rules->counter++;
		i++;
	}
	i = 0;
	while (i < rules->nbr_of_philo)
	{
		pthread_join(rules->philo[i].phil, NULL);
		i++;
	}
}

int	main(int ac, char	**av)
{
	t_rules rules;
	
	if (ac == 5)
		parse_arguments(&rules, av, 0);
	else if (ac == 6)
		parse_arguments(&rules, av, 1);
}
