/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:37:48 by cjad              #+#    #+#             */
/*   Updated: 2022/03/27 15:59:36 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

int	check(char c)
{
	if (!(c >= '0' && c <= '9'))
	{
		printf("Error\nArgument is not numeric.\n");
		return (-1);
	}
	return (0);
}

long	result(const char	*str, int i, int s)
{
	size_t	n;
	size_t	tmp;

	n = 0;
	tmp = 0;
	if (check(str[i]) < 0)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = str[i] - '0' + n * 10;
		if ((n > INT_MAX && n != 2147483648) || (n == 2147483648 && s == 1))
		{
			printf("Error\nNumber not an intiger.\n");
			return (-1);
		}
		tmp = n;
		i++;
	}
	if (str[i] != '\0')
	{
		printf("Error\nArgument is not numeric.\n");
		return (-1);
	}
	return (n);
}

int	sign_check(char *str, int *s, int *i)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*s = -*s;
		(*i)++;
	}
	if ((str[*i] == '-' || str[*i] == '+')
		|| (str[*i] >= '\t' && str[*i] <= '\r') || str[*i] == ' ')
	{
		printf("Error\nArgument is not numeric.\n");
		return (-1);
	}
	return (0);
}

int	ft_atoi(char	*str)
{
	int		i;
	long	n;
	int		s;

	i = 0;
	s = 1;
	n = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (sign_check(&str[i], &s, &i) < 0)
		return (-1);
	n = result(str, i, s);
	if (n < 0)
		return (-1);
	return (n * s);
}
