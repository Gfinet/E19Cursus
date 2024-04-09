/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:23:02 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/09 15:25:58 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	free_all_pipex(t_cmds *c, pid_t *proc )
{
	if (c)
		free_t_cmd(c);
	if (proc)
		free(proc);
	return (0);
}

void	free_t_cmd(t_cmds *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < c->nb_pr && c->arg && c->cmd_arg && c->cmd_arg[i])
		if (c->cmd_arg[i])
			free(c->cmd_arg[i++]);
	if (c->cmd_arg)
		free(c->cmd_arg);
	while (--i >= 0 && c->arg && c->arg[i])
	{
		if (c->arg[i])
		{
			j = 0;
			while (c->arg[i][j])
				free(c->arg[i][j++]);
		}
		free(c->arg[i]);
	}
	if (c->arg)
		free(c->arg);
	while (c->path && c->path[++i])
		free(c->path[i]);
	if (c->path)
		free(c->path);
}

void	open_files(int argc, char **argv, int r_w_fd[])
{
	r_w_fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (r_w_fd[1] == -1)
		send_error(-1);
	r_w_fd[0] = open(argv[1], O_RDONLY);
	if (r_w_fd[0] == -1)
		send_error(-1);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmds	c;
	int		flag;
	int		r_w_fd[2];

	if (argc != 5 || !argv || !envp)
		return (send_error(-7));
	flag = check_file_perm(argv[1], argv[argc - 1]);
	if (flag <= 0)
		return (send_error(flag));
	flag = init_t_cmds(&c, argc, envp);
	if (flag < 0)
		return (free_t_cmd(&c), send_error(flag));
	flag = find_all_path(&c, argv, argc - 3);
	if (flag == -8)
		search_cmd(&c);
	else if (flag < 0)
		return (free_t_cmd(&c), send_error(flag));
	open_files(argc, argv, r_w_fd);
	if (commands(&c, r_w_fd, envp) == -5)
		return (send_error(-5), errno);
	return (0);
}

/*
Pipex
1) Trouver la commande
2) Verifier acces a la commade
3) Effectuer commande sur file1
4) Recuperer output de la commande
5) Envoyer output de commande1 sur commande 2
6) emvoyer output de commande 2 sur file 2
*/