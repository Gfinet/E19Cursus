/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 22:15:11 by Gfinet            #+#    #+#             */
/*   Updated: 2024/03/17 22:24:13 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	check_isspace(char c)
{
	if (c == ' ')
		return (1);
	return (c == '\f' || c == '\n' || c == '\t' || c == '\r' || c == '\v');
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
