/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:16:52 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/08 17:52:45 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	check_file_perm(char *open_file, char *write_file)
{
	if (access(open_file, F_OK))
	{
		ft_printf("%s: ", open_file);
		if (access(write_file, F_OK))
			open(write_file, O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		return (-1);
	}
	else if (access(open_file, R_OK))
		return (ft_printf("\"%s\" ", open_file), -9);
	if (access(write_file, F_OK) == 0)
		if (access(write_file, R_OK))
			return (ft_printf("\"%s\" ", write_file), -9);
	return (1);
}

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
		perror("bad argument");
	}
	else if (flag == -8)
		perror("access error");
	else if (flag == -9)
		perror("permission error");
	else if (flag == -10)
		perror("PATH not found");
	return (errno);
}

void	search_cmd(t_cmds *c)
{
	int	i;

	i = 0;
	while (i < c->nb_pr)
	{
		if (access(c->cmd_arg[i], F_OK) != 0)
		{
			ft_printf("\"%s\" ", c->arg[i][0]);
			perror("access error");
		}
		else if (access(c->cmd_arg[i], X_OK) != 0)
		{
			ft_printf("\"%s\" ", c->arg[i][0]);
			perror("access error");
		}
		i++;
	}
}
