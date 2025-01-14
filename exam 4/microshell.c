/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:49:45 by gfinet            #+#    #+#             */
/*   Updated: 2025/01/06 17:48:27 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_cmd
{
	char	**buff;
	char	sep;
	int		pipe[2];
	int		cur;
	int		nb_cmd;
	pid_t	*proc;
}	t_cmd;

void print_cmd(char **buff)
{
	int k = 0;

	while (buff[k])
			printf("%s ", buff[k++]);
		printf("\n");
}

char **cut_cmd(int *i, char **av, int *j)
{
	int k;
	char **buf;

	*j = 0;
	while (av[(*i) + (*j)] != 0 && strcmp(av[(*i) + (*j)], "|") && strcmp(av[(*i) + (*j)], ";"))
		(*j)++;
	buf = malloc(sizeof(char *) * (*j + 1));
	buf[(*j)] = 0;
	k = 0;
	while (k < (*j))
	{
		buf[k] = av[(*i) + k];
		k++;
	}
	*i+=(*j);
	return (buf);
}

int count_proc(char **av)
{
	int nb = 0, i = 0, flag = 0;

	while (av[++i])
	{
		if (strcmp(av[i], "|") && strcmp(av[i], ";") && !flag)
		{
			nb++;
			flag = 1;
		}
		else if (!strcmp(av[i], "|") || !strcmp(av[i], ";"))
			flag = 0;
	}
	return (nb);
}

void launch_cmd(t_cmd *cmd, char **envp, int pip[2], int pipe_fd[2])
{
	//printf("launch cmd %s\n", cmd->buff[0]);
    // Si c'est une commande avec un pipe en sortie
    if (pip[0])
        if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
            exit(EXIT_FAILURE);

    // Si c'est une commande avec un pipe en entrée
    if (pip[1])
        if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
            exit(EXIT_FAILURE);

    if (pipe_fd[0] > 2)
		close(pipe_fd[0]);
    if (pipe_fd[1] > 2)
		close(pipe_fd[1]);

    execve(cmd->buff[0], cmd->buff, envp);

    exit(EXIT_FAILURE);
}

int cd(t_cmd *cmd)
{
	int k = 0;

	while (cmd->buff[k])
		k++;
	if (k > 2)
		return (write(2, "error: cd: bad arguments\n", 25), 1);
	k = 0;
	while (cmd->buff[1][k])
		k++;
	if (chdir(cmd->buff[1]) == -1)
		return (write(2, "error: cd: cannot change directory to ", 38), write(2, cmd->buff[1], k), write(2, "\n", 1), 1);
	return (0);	
}

int main(int ac, char **av, char **env)
{
    t_cmd cmd;
    int i, j, inf = -1, pip[2], pipe_fd[2];

    i = 0;
    cmd = (t_cmd){0};
    if (ac < 2)
        return (1);

    cmd.nb_cmd = count_proc(av);
	if (!cmd.nb_cmd)
		return 0;
    // printf("nb : %d\nsep : [%s]\n", cmd.nb_cmd, cmd.sep);
    cmd.proc = malloc(sizeof(pid_t) * (cmd.nb_cmd + 1));

    while (i++ < ac)
    {
		while (av[i] && !strcmp(av[i], ";"))
			i++;
		if (!av[i])
			break;
		cmd.sep = av[i - 1][0];
        cmd.buff = cut_cmd(&i, av, &j);
        if (!cmd.buff)
            return (write(2, "error: fatal\n", 13), 1);
			 //print_cmd(cmd.buff);
		
		if (!strcmp(cmd.buff[0], "cd"))
			return (free(cmd.proc), cd(&cmd));
		else
        {
			// printf("pr %s\n", cmd.buff[0]);
			// printf("cmd.sep %c\n", cmd.sep);
			pip[0] = (cmd.nb_cmd > 1 && av[i] && !strcmp(av[i], "|"));
			pip[1] = (cmd.cur && cmd.cur < cmd.nb_cmd && cmd.sep == '|');

			if (pip[0] && pipe(pipe_fd) < 0)
				return (write(2, "error: fatal\n", 13), 1);
			print_cmd(cmd.buff);
			printf("%d %d %d\n", pip[0], pip[1], cmd.nb_cmd );
			cmd.proc[cmd.cur] = fork();
			if (cmd.proc[cmd.cur] == 0)
				launch_cmd(&cmd, env, pip, (int[2]){inf, pipe_fd[1]});

			if (inf != -1)
				close(inf);
			if (pip[0])
			{
				close(pipe_fd[1]);
				inf = pipe_fd[0];
			}
			else
				inf = -1;
			//printf("%d %d %d\n", inf, pipe_fd[0], pipe_fd[1]);
		}
        free(cmd.buff);
        cmd.cur++;
    }
    cmd.cur = -1;
    while (++cmd.cur < cmd.nb_cmd)
        waitpid(cmd.proc[cmd.cur], 0, 0);
    free(cmd.proc);
    return (0);
}

/*
Meta_code :

main()
{
	check_nb_arg();
	while (iterateur de la ligne)
	{
		get_one_cmd();
		setting_flag_for_pipe(pipe_entree_sortie);
		if (pipe_entree_sortie[0])
			pipe(pipe_fd);
		fork()
		{
			launch_cmd(save_fd, pipe_fd[1], env);
		}
		if (save_fd != -1)
			close(save_fd);
		if (pipe_entree_sortie[0])
		{
			close(pipe_fd[1])
			save_fd = pipe_fd[0];
   			close(pipe_fd[0]); //?
		}
		else
			save_fd = -1;
	}
	if (wait_proc(proc, status) == -1)
		write(proc bug);
	free_all();
}

*/
