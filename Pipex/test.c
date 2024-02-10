/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:58:20 by gfinet            #+#    #+#             */
/*   Updated: 2024/02/10 19:32:43 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/*
ls
cat
grep
wc
script.sh

cd ?

*/

int main(int argc, char **argv, char **envp)
{
	pid_t proc[10];

	if (access("./pipex", F_OK) != 0)
	{
		proc[0] = fork();
		if (proc[0] == 0)
			execve("make", (char *[]){"make", NULL}, envp);
		ft_printf("make done\n");
	}
	
	ft_printf("----- Test cat ls -----\n\n");

	execve("pipex", (char *[]){"pipex", "infile", "cat", "ls", "outfile", NULL}, envp);
	execve("");

	proc[9] = fork();
	if (proc[9] == 0)
	{
		execve("diff", (char *[]){"diff", "outfile1", "outfile2", NULL}, envp);
	}

	return (0);
}

/*
1 fichier infile
2 fichier outfile
lancer pipex infile outfile1
lancer command infile outfile2
lancer diff outfile1 outfile2


*/