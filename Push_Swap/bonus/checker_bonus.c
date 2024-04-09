/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:52:29 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/09 03:19:16 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "get_next_line_bonus.h"

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

int	check_input(char **s, int n_arg)
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

void	make_move(t_nlst_head *a, t_nlst_head *b, char *move)
{
	if (move[0] == 'p' && move[1] == 'a')
		push(b, a, 0);
	else if (move[0] == 'p' && move[1] == 'a')
		push(a, b, 1);
	else if (move[0] == 'r' && move[1] == 'a')
		rotate(a, 0, 0);
	else if (move[0] == 'r' && move[1] == 'b')
		rotate(b, 0, 1);
	else if (move[0] == 'r' && move[1] == 'r')
		rotate(a, b, 2);
	else if (move[0] == 's' && move[1] == 'a')
		swap(a, 0, 0);
	else if (move[0] == 's' && move[1] == 'b')
		swap(b, 0, 1);
	else if (move[0] == 's' && move[1] == 's')
		swap(a, b, 2);
}

//ft_printf("%d", ft_strlen(move));
static int	emule_ps_answer(char **arg, int nb_arg)
{
	t_nlst_head	*a;
	t_nlst_head	*b;
	char		*move;

	move = get_next_line(0);
	a = NULL;
	b = NULL;
	if (!fill_a(a, arg, nb_arg))
		return (-1);
	while (move)
	{
		if (ft_strlen(move) == 4)
		{
			if (move[0] == 'r' && move[2] == 'a')
				reverse_rotate(a, 0, 0);
			else if (move[0] == 'r' && move[2] == 'b')
				reverse_rotate(b, 0, 1);
			else if (move[0] == 'r' && move[2] == 'r')
				reverse_rotate(a, b, 2);
		}
		else
			make_move(a, b, move);
		move = get_next_line(0);
	}
	return (check_heap(a->first, 0) && ft_nlstsize(b) == 0);
}

int	main(int argc, char **argv)
{
	int		nb_elem;
	char	**nums;
	int		res;

	nums = 0;
	if (argc < 2 || !argv[1][0])
		return (0);
	if (!parse_arg(argc, argv, &nums, &nb_elem) || !check_input(nums, nb_elem))
		write(2, "Error\n", 6);
	else
	{
		res = emule_ps_answer(nums, nb_elem);
		if (res == 1)
			write(1, "OK\n", 3);
		else if (res == 0)
			write(1, "KO\n", 3);
		else
			write(2, "Error\n", 6);
	}
	return (0);
}
