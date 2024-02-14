/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:52:05 by Gfinet            #+#    #+#             */
/*   Updated: 2024/02/13 23:58:48 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	pipex(t_cmds *c, pid_t *proc, int pipe_fd[], char **envp)
{
	int	i;
	int	in_fd;

	i = 0;
	if (pipe(pipe_fd) < 0)
		send_error(-6);
	while (i < c->nb_pr)
	{
		//print_cmd_i(c, i);
		proc[i] = fork();
		if (proc[i] < 0)
			send_error(-4);
		if (i > 0)
			dup2(in_fd, STDIN_FILENO);
		if (proc[i] == 0)
			launch_cmd(c, pipe_fd, envp, i);
		if (i > 0)
			close(in_fd);
		close(pipe_fd[1]);
		in_fd = pipe_fd[0];
		if (i < c->nb_pr - 1)
			if (pipe(pipe_fd) < 0)
				send_error(-6);
		i++;
	}
	return (in_fd);
}

int	commands(t_cmds *c, int write_fd, char **envp)
{
	pid_t	*proc;
	int		in_fd;
	int		pipe_fd[2];
	int		flag;

	proc = malloc(sizeof(pid_t) * c->nb_pr);
	in_fd = pipex(c, proc, pipe_fd, envp);
	flag = write_file(in_fd, write_fd);
	if (flag < 0)
		send_error(flag);
	free_all_pipex(c, proc);
	return (1);
}
