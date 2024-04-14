/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 00:59:08 by Gfinet            #+#    #+#             */
/*   Updated: 2024/04/14 19:57:58 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

int equal_int(char *s1, char *s2)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (!is_number(s1))
		return (0);
	if (s1[0] == '-' && s1[0] == s2[0])
		i++;
	j = i;
	while (s1[i] == '0')
		i++;
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	if (s1[i] != s2[j])
		return (0);
	return (1);
}

int	check_input(char **s, int n_arg)
{
	int		i;
	int		j;
	char	*tmp;
	int		flag;

	i = 0;
	while (s[i])
	{
		flag = ft_atoi(s[i]);
		tmp = ft_itoa(flag);
		if (flag && !equal_int(s[i], tmp))
			return (free(tmp), 0);
		free(tmp);
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

int	parse_arg(int argc, char **argv, char ***nums, int *nb_elem)
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

//ft_printf("moves : %d\n", res->one);
//ft_printf("sorted : %d", res->two);
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
		if (!res)
			write(2, "Error\n", 6);
		else
			free(res);
	}
	return (0);
}
