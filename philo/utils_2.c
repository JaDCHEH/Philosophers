#include "philo.h"

void	ft_usleep(int num)
{
	int	start;
	int	current;

	start = get_time() + num;
	current = get_time();
	while (start > current)
	{
		current = get_time();
		usleep(10);
	}
}