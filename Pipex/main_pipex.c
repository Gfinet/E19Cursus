/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:23:02 by gfinet            #+#    #+#             */
/*   Updated: 2024/02/03 23:12:08 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
//./pipex file 1 cmd1 cmd2 file2



int main(int argc, char **argv, char **envp)
{
	char **arg;
	char **path;
	char *p2;
	int i;

	i = 0;
	if (argc < 5 || !argv) /// != 5
		return (0);
	while(*(envp) && ft_strncmp(*(++envp), "PATH", 4));
	path = ft_split(*(envp), ':');
	ft_printf("env %s\n\n", *envp);
	// while (*path)
	// 	ft_printf("path = %s\n", *path++);
	arg = ft_split(argv[2], ' ');
	p2 = ft_strjoin(path[i], "/");
	p2 = ft_stradd(p2, arg[0]);
	// i = 0;
	// while(path[i])
	// 	ft_printf("path = %s\n", path[i++]);
	i = 0;
	while(path[i])
	{
		ft_printf("path = %s\n", path[i++]);
		//ft_printf("%i %d\n", path[i] != 0, access(p2, F_OK) == -1);
		if (access(p2, F_OK) == 0)
			break;
		free(p2);
		p2 = ft_strjoin(path[i], "/");
		p2 = ft_stradd(p2, arg[0]);
		i++;
	}
	execve(p2, arg, path);
	free(p2);
	return (0);
}

/*
Pipex
1) Trouver la commande
2) Verifier acces a la commade
3) Effectuer commade sur file1
4) Recuperer output de la commande
5) Envoyer output de commande1 sur commande 2
6) emvoyer output de commande 2 sur file 2

*/