/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:16:52 by gfinet            #+#    #+#             */
/*   Updated: 2024/02/10 21:47:50 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	send_error(int flag)
{
	if (flag == -1)
		perror("open error");
	else if (flag == -2)
		perror("read error");
	else if (flag == -3)
		perror("write error");
	else if (flag == -4)
		perror("fork error");
	else if (flag == -5)
		perror("malloc error");
	else if (flag == -6)
		perror("pipe error");
	else if (flag == -7)
	{
		errno = 5;
		perror("Not enough argument");
	}
	else if (flag == -8)
		perror("access error");
	return (errno);
}

int search_cmd(t_cmds *c)
{
	int i;

	i = 0;
	while (i < c->nb_pr)
	{
		if (access(c->cmd_arg[i], F_OK) != 0)
		{
			ft_printf("\"%s\" ", c->arg[i][0]);
			perror("access error");
		}
		i++;
	}
	free_t_cmd(c);
	exit();
	return (errno);
}

//errno = 2 == no such file or dir