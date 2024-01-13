/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 00:59:08 by Gfinet            #+#    #+#             */
/*   Updated: 2024/01/13 19:58:55 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *s)
{
	int	len;
	int	i;

	len = ft_strlen(s);
	i = (s[0] == '-');
	if (i && len == 1)
		return (0);
	while (i < len)
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int check_input(char **s, int n_arg)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = i + 1;
		while (j < n_arg && s[j])
		{
			if (ft_atoi(s[i]) == ft_atoi(s[j]))
				return (0);
			j++;
		}
		if (!is_number(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_res	*res;
	int		nb_elem;
	char	**nums;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		ft_printf("sdbkfjhgadskfjbghqrwihn\n");
		nb_elem = 0;
		while (nums[nb_elem])
			nb_elem++;
		res = push_swap(nums, nb_elem);
		ft_printf("check input = %i\n", check_input(nums, nb_elem));
	}
	else
	{
		res = push_swap(&argv[1], argc - 1);
		ft_printf("check input = %i\n", check_input(&argv[1], argc - 1));
	}
	
	ft_printf("push_swap = %i\n", res->sorted);
	ft_printf("moves = %i\n", res->moves);
	free(res);
	return (0);
}

/*
10 32 17 48 94 60 54 29 64 73 45 62 49 67 16 61 22 90 53 84 34 12 95 41 82 8 99 46 37 66 79 26 15 65 91 30 93 47 43 18 7 11 19 44 88 75 2 14 1 86
7 28 22 86 81 27 39 45 41 60 65 51 6 13 3 50 70 71 92 37 19 42 93 64 69 18 25 43 96 73 15 52 99 77 47 88 9 87 12 44 11 59 82 90 16 55 91 79 80 74
*/