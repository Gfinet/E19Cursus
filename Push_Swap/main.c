/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 00:59:08 by Gfinet            #+#    #+#             */
/*   Updated: 2024/01/23 19:52:45 by gfinet           ###   ########.fr       */
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

static int	check_input(char **s, int n_arg)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		if (ft_strlen(s[i]) != ft_strlen(ft_itoa(ft_atoi(s[i]))))
			return (0);
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

static int	parse_arg(int argc, char **argv, char ***nums, int *nb_elem)
{
	int		i;
	char	**l;

	i = 0;
	if (argc == 2)
	{
		l = ft_split(argv[1], ' ');
		if (!l)
			return (0);
		while (l[i])
			i++;
		*nb_elem = i;
		*nums = l;
	}
	else
	{
		*nums = &argv[1];
		*nb_elem = argc - 1;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_2_int	*res;
	int		nb_elem;
	char	**nums;

	nums = 0;
	if (argc < 2 || !argv[1][0])
		return (0);
	if (!parse_arg(argc, argv, &nums, &nb_elem) || !check_input(nums, nb_elem))
		write(2, "Error\n", 6);
	else
	{
		res = push_swap(nums, nb_elem);
		//ft_printf("moves : %d", res->one);
		if (!res)
			write(2, "Error\n", 6);
		else
			free(res);
	}
	return (0);
}
