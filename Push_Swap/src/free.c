/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:04:52 by gfinet            #+#    #+#             */
/*   Updated: 2024/05/19 20:45:07 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	strarray_free(char **p, int flag)
{
	int	i;

	i = -1;
	while (flag && p && p[++i])
		free(p[i]);
	if (flag)
		free(p);
}
