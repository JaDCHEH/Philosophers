#include "philo.h"

void	routine(t_rules *rules)
{
	int	i;

	i = rules->counter;
	rules->philo[i].start_time = get_time();
	while (rules->philo_alive)
	{
		philo_eat(rules, &rules->philo[i]);
		philo_do(&rules->philo[i], rules, rules->time_to_sleep, "is sleeping");
		print_action(&rules->philo[i], rules, "is thinking");
	}
}

void	death_c(t_rules *rules)
{
	int	i;

	i = 0;
	while(1)
	{
		while (i < rules->nbr_of_philo)
		{
			death_check(&rules->philo[i], rules);
			i++;
		}
		i = 0;
	}
}

void	creat_threads(t_rules *rules)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < rules->nbr_of_philo)
	{
		pthread_create(&rules->philo[i].phil, NULL, (void *)routine, rules);
		usleep(50);
		rules->counter++;
		i++;
	}
	i = 0;
	pthread_create(&rules->death[j], NULL,(void *)death_c,rules);
	j = 0;
	while (i < rules->nbr_of_philo)
	{
		pthread_join(rules->philo[i].phil, NULL);
		i++;
	}
		pthread_join(rules->death[j], NULL);
}

int	main(int ac, char	**av)
{
	t_rules rules;
	
	if (ac == 5)
		parse_arguments(&rules, av, 0);
	else if (ac == 6)
		parse_arguments(&rules, av, 1);
}
