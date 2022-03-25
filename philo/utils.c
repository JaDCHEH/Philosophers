#include "philo.h"

void	print_action(t_philo *philo, t_rules *rules, char	*str)
{
	int	i;

	i = get_time() - philo->start_time;
	printf("%d %d %s \n", i, philo->philo_id, str);
}

int	find_max(t_philo *philo)
{
	if (philo->l_fork > philo->r_fork)
		return(philo->l_fork);
	else
		return(philo->r_fork);
}

int	find_min(t_philo *philo)
{
	if (philo->l_fork < philo->r_fork)
		return(philo->l_fork);
	else
		return(philo->r_fork);
}

void	philo_do(t_philo *philo, t_rules *rules, int r, char *str)
{
	print_action(philo, rules, str);
	ft_usleep(r);
}

int	get_time(void)
{
	struct timeval	a;
	gettimeofday(&a, NULL);
	return (a.tv_sec * 1000 + a.tv_usec / 1000);
}