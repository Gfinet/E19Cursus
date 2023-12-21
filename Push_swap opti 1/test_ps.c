/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:21:35 by Gfinet            #+#    #+#             */
/*   Updated: 2023/12/21 21:21:11 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int free_all(char **arg, int len)
{
	int i = 0;
	
	while (i < len)
		free(arg[i++]);
	free(arg);
	return (0);
}

static int make_rand_arg(int range, char **arg, int set)
{
	int num;
	int i;

	i = 0;
	srand(set);
	while (i < range)
	{
		num = rand() % 100 +1 ;
		arg[i] = malloc(ft_strlen(ft_itoa(num)));
		if (!arg[i])
			return (free_all(arg, i));
		arg[i] = ft_itoa(num);
		i++;
	}
	return (1);
}


int main(int argc, char **argv)
{
	int range;
	int nb_test;
	int i = 0;
	char **arg;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		range = 5;
		nb_test = ft_atoi(argv[1]);
		arg = malloc(sizeof(char *) * range);
		while (i < nb_test)
		{
			if (!make_rand_arg(range, arg, i))\
				return (free_all(arg, i));
			printf("--- test %i ---\nsorted : %s\n", i+1, push_swap(arg, range) ? "yes" : "no");
			free_all(arg, range);
			arg = malloc(sizeof(char *) * range);
			i++;
		}
		free_all(arg, range);
	}
	return (0);
}