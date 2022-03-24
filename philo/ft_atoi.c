/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:37:48 by cjad              #+#    #+#             */
/*   Updated: 2022/03/21 16:12:37 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

void	check(char c)
{
	if (!(c >= '0' && c <= '9'))
	{
		write(2, "Error\n", 7);
		exit(1);
	}
}

long	result(const char	*str, int i, int s)
{
	size_t	n;
	size_t	tmp;

	n = 0;
	tmp = 0;
	check(str[i]);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = str[i] - '0' + n * 10;
		if ((n > INT_MAX && n != 2147483648) || (n == 2147483648 && s == 1))
		{
			write(2, "Error\n", 7);
			exit(1);
		}
		tmp = n;
		i++;
	}
	if (str[i] != '\0')
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	return (n);
}

void	check_1(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if ((str[a] >= '\t' && str[a] <= '\r') || str[a] == ' '
			|| (str[a] >= '0' && str[a] <= '9')
			|| str[a] == '+')
			a++;
		else
		{
			write(2, "Error\n", 7);
			exit(1);
		}
	}
}

int	ft_atoi(char	*str)
{
	int		i;
	long	n;
	int		s;

	i = 0;
	s = 1;
	n = 0;
	check_1(str);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' 
		|| (str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	n = result (str, i, s);
	return (n * s);
}
