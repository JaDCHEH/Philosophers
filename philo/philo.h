#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

int	ft_atoi(char	*str);

typedef struct s_struct
{
	pthread_t 	phil;
	int	philo_id;
	int l_fork;
	int r_fork;
	int	start_time;
	int	lst_meal;
	int	philo_n_eat;
} t_philo;

typedef struct s_st
{
	pthread_mutex_t			*forks;
	pthread_mutex_t			mulock;
	t_philo 				*philo;
	int						nbr_of_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						nbr_of_eat;
	int						counter;
} t_rules;

void	init_philo(t_rules *rules);
void	parse_arguments(t_rules *rules, char **av, int j);
void	print_action(t_philo *philo, char	*str);
int		find_max(t_philo *philo);
int		find_min(t_philo *philo);
void	philo_do(t_philo *philo, int r, char *str);
void	creat_threads(t_rules *rules);
int		get_time(void);
void	ft_usleep(int num);

#endif