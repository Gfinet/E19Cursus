/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:30:13 by Gfinet            #+#    #+#             */
/*   Updated: 2023/12/12 19:29:41 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_input(char **s)
{
    int i;
    int j;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (s[i][j])
        {
            if (!ft_isdigit(s[i][j]) || s[i][j] != '-')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

static int    fill_a(t_list **a, char **arg)
{
    t_list  *p;
    int     i;
    int     num;

    i = 0;
    while (arg[i])
    {
        num = arg[i] - '0';
        p = ft_plstnew(num);
        if (!p)
            return (ft_plstclear(a, free));
        ft_plstadd_back(a, p);
        i++;
    }
    return (1);
}

int push_swap(char **arg)
{
    t_list  *a;
    t_list  *b;

    if (!fill_a(&a, arg))
        return (0);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    if (!check_input(&argv[1]))
        return (0);
    if (!push_swap(&argv[1]))
        return (0);
    return (0);
}