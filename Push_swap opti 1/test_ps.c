/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:21:35 by Gfinet            #+#    #+#             */
/*   Updated: 2023/12/24 15:22:10 by Gfinet           ###   ########.fr       */
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

static int in_list(int num, char **arg, int range)
{
	int i;

	i = 0;
	while (arg[i] && i < range)
	{
		if (ft_atoi(arg[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void set_arg_null(char **arg, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		arg[i] = NULL;
		i++;
	}
}

void set_big_arg(char **arg, int len)
{
	int i = 0;

	while (i < len)
	{
		arg[i] = malloc(4);
		i++;
	}
}

static int make_rand_arg(int range, char **arg, int set)
{
	int num;
	int i;

	i = 0;
	srand(set * time(0));
	while (i < range)
	{
		num = rand() % 500 +1;
		while (in_list(num, arg, i))
			num = rand() % 50 +1;
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
	int *moves;
	int i = 0;
	int total = 0;
	int biggest = 0;
	int biggest_moves = 0;

	char **arg;
	char **big_arg;
	t_res *res;

	time_t diff;

	if (argc < 3)
		return (0);
	if (argc == 3)
	{
		diff = time(NULL);
		range = ft_atoi(argv[2]);
		if (range < 2)
			return (0);
		nb_test = ft_atoi(argv[1]);
		moves = malloc(sizeof(int) * nb_test);
		arg = malloc(sizeof(char *) * range);
		big_arg = malloc(sizeof(char *) * range);
		set_arg_null(arg, range);
		set_arg_null(big_arg,range);
		set_big_arg(big_arg, range);
		while (i < nb_test)
		{
			if (!make_rand_arg(range, arg, i))\
				return (free_all(arg, i));
			ft_printf("---------------- test %i ----------------\n", i+1);
			res = push_swap(arg, range);
			printf("\nsorted : %s\n", res->sorted ? "yes" : "no");
			printf("moves : %d\n\n", res->moves);
			if (res->moves >= biggest_moves)
			{
				biggest_moves = res->moves;
				biggest = i + 1;
				i = 0;
				while (i < range)
				{
					ft_strlcpy(big_arg[i], arg[i], 4);
					i++;
				}
				i = biggest - 1;
			}
			moves[i] = res->moves;
			total += moves[i];
			free_all(arg, range);
			arg = malloc(sizeof(char *) * range);
			i++;
		}
		free(arg);
		printf("--- for %i numbers, %i tests ---\nmoyenne moves : %i\n\n", range, nb_test, total / nb_test);
		diff = time(NULL) - diff;
		printf("time spend : %ld sec\n", diff);
		printf("biggest iteration: %i\n", biggest);
		printf("moves : %d\n\n", biggest_moves);
		res = push_swap(big_arg, range);
		free_all(big_arg,range);
	}
	return (0);
}