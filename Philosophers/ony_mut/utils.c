/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:15:11 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/03 19:43:37 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_isspace(char c)
{
	if (c == ' ')
		return (1);
	return (c == '\f' || c == '\n' || c == '\t' || c == '\r' || c == '\v');
}

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		minus;

	i = 0;
	res = 0;
	minus = 0;
	while (check_isspace(str[i]))
		i++;
	minus = (str[i] == '-');
	i += (str[i] == '-' || str[i] == '+');
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	if (minus)
		res *= -1;
	return (res);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	minus;

	i = 0;
	res = 0;
	minus = 0;
	while (check_isspace(str[i]))
		i++;
	minus = (str[i] == '-');
	i += (str[i] == '-' || str[i] == '+');
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	if (minus)
		res *= -1;
	return (res);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long	get_time(long start)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000 - start);
}
