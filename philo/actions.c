#include "philo.h"

void	philo_eat(t_rules *rules, t_philo *philo)
{
	pthread_mutex_lock(&rules->forks[philo->l_fork]);
	print_action(philo, rules, "has taken a fork");
	pthread_mutex_lock(&rules->forks[philo->r_fork]);
	print_action(philo, rules, "has taken a fork");
	philo->lst_meal = get_time() - philo->start_time;
	philo_do(philo, rules, rules->time_to_eat,"is eating");
	pthread_mutex_unlock(&rules->forks[philo->l_fork]);
	pthread_mutex_unlock(&rules->forks[philo->r_fork]);
}

void	death_check(t_philo *philo, t_rules *rules)
{
	int i;

	i =  get_time() - philo->start_time - philo->lst_meal;
	if (i >= rules->time_to_die)
	{
		pthread_mutex_lock(&rules->mulock);
		print_action(philo, rules, "has died");
		exit(1);
		pthread_mutex_unlock(&rules->mulock);
	}
}