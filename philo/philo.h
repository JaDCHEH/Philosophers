/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:54:19 by cjad              #+#    #+#             */
/*   Updated: 2022/03/28 18:45:57 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_struct
{
	pthread_t	phil;
	int			philo_id;
	int			l_fork;
	int			r_fork;
	int			lst_meal;
	int			philo_n_eat;
	int			start_time;
}	t_philo;

typedef struct s_st
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	mulock;
	pthread_mutex_t	end_lock;
	t_philo			*philo;
	pthread_t		death;
	int				death_counter;
	int				all_ate;
	int				nbr_of_philo;
	int				time_to_die;
	int				philo_alive;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_eat;
	int				counter;
}	t_rules;

int		ft_atoi(char	*str);
int		get_time(void);
int		meal_check(t_rules *rules);
int		create_threads(t_rules *rules);
int		join_threads(t_rules *rules);
int		philosophers(t_rules *rules, char **av, int j);
int		init_philo(t_rules *rules);

void	destroy_mutex(t_rules *rules);
void	print_action(t_philo *philo, char	*str);
void	philo_do(t_philo *philo, t_rules *rules, int r, char *str);
void	ft_usleep(int num, int a);
void	philo_eat(t_rules *rules, t_philo *philo);
void	death_check(t_philo *philo, t_rules *rules);

#endif
