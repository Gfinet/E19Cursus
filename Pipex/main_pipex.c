/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:23:02 by gfinet            #+#    #+#             */
/*   Updated: 2024/02/13 23:47:57 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	free_all_pipex(t_cmds *c, pid_t *proc )
{
	if (c)
		free_t_cmd(c);
	if (proc)
		free(proc);
	return (0);
}

int	write_file(int read_fd, int write_fd)
{
	int		read_byte;
	char	buff[BUFFER_SIZE];

	read_byte = BUFFER_SIZE;
	while (read_byte > 0 && read_byte == BUFFER_SIZE)
	{
		read_byte = read(read_fd, buff, BUFFER_SIZE);
		if (read_byte == -1)
			return (-2);
		if (read_byte > 0)
		{
			if (write(write_fd, buff, read_byte) == -1)
				return (-3);
		}
	}
	close(write_fd);
	return (1);
}

void	free_t_cmd(t_cmds *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < c->nb_pr)
		if (c->cmd_arg[i])
			free(c->cmd_arg[i++]);
	free(c->cmd_arg);
	i = 0;
	while (i < c->nb_pr)
	{
		if (c->arg[i])
		{
			j = 0;
			while (c->arg[i][j])
				free(c->arg[i][j++]);
		}
		free(c->arg[i++]);
	}
	free(c->arg);
	i = 0;
	while (c->path[i])
		free(c->path[i++]);
	free(c->path);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmds	c;
	int		flag;
	int		write_fd;


	if (argc != 5 || !argv || !envp)
		return (send_error(-7));
	if (check_file_perm(argv[1], argv[argc - 1]))
		return (0);
	flag = init_t_cmds(&c, argc, envp);
	if (flag < 0)
		return (send_error(flag));
	flag = find_all_path(&c, argv, argc - 3);
	if (flag == -8)
		return (search_cmd(&c));
	else if (flag < 0)
		return (send_error(flag));
	write_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (write_fd == -1)
		return (send_error(-1));
	if (!commands(&c, write_fd, envp))
		return (errno);
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

int j = 0;
		while (c->arg[i][j])
			{ft_printf("com %d ", i);ft_printf("%s\n", c->arg[i][j++]);}

*/