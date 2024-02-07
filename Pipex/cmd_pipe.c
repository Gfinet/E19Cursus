/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:52:05 by Gfinet            #+#    #+#             */
/*   Updated: 2024/02/07 17:47:41 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	launch_cmd(t_cmds *c, int pipe_fd[], char **envp, int pr)
{
	ft_printf("CHILD %d\n", pr);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execve(c->cmd_arg[pr], c->arg[pr], envp);
	_exit(EXIT_FAILURE);
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
	free_t_cmd(c);
	free(proc);
	return (1);
}
