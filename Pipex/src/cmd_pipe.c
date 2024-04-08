/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:52:05 by Gfinet            #+#    #+#             */
/*   Updated: 2024/04/08 17:53:24 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	launch_cmd(t_cmds *c, int pipe_fd[], char **envp, int pr)
{
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execve(c->cmd_arg[pr], c->arg[pr], envp);
	exit(EXIT_FAILURE);
}

void	print_cmd_i(t_cmds *c, int i)
{
	int	j;

	j = 0;
	ft_printf("command : %s\n", c->cmd_arg[i]);
	while (c->arg[i][j])
	{
		ft_printf("arg %d", j);
		ft_printf(" : %s\n", c->arg[i][j]);
		j++;
	}
}

void	pipex(t_cmds *c, pid_t *proc, int r_w_fd[], char **envp)
{
	int	i;
	int	pipe_fd[2];

	i = -1;
	while (++i < c->nb_pr)
	{
		if (i < c->nb_pr - 1)
			if (pipe(pipe_fd) < 0)
				send_error(-6);
		proc[i] = fork();
		if (proc[i] < 0)
			send_error(-4);
		if (proc[i] == 0)
		{
			dup2(r_w_fd[0], STDIN_FILENO);
			if (i == c->nb_pr - 1)
				launch_cmd(c, r_w_fd, envp, i);
			else
				launch_cmd(c, pipe_fd, envp, i);
		}
		if (r_w_fd[0] != 0)
			close(r_w_fd[0]);
		close(pipe_fd[1]);
		r_w_fd[0] = pipe_fd[0];
	}
}

int	commands(t_cmds *c, int r_w_fd[], char **envp)
{
	pid_t	*proc;
	int		i;

	proc = malloc(sizeof(pid_t) * c->nb_pr);
	if (!proc)
		return (-5);
	pipex(c, proc, r_w_fd, envp);
	i = 0;
	while (i < c->nb_pr)
	{
		waitpid(proc[i], 0, 0);
		i++;
	}
	free_all_pipex(c, proc);
	return (1);
}
