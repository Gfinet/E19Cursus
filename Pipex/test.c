/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:58:20 by gfinet            #+#    #+#             */
/*   Updated: 2024/02/12 18:01:06 by Gfinet           ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	char	**sp;

	argc = argc + argc;
	sp = ft_split(argv[1], ' ');
	execve(sp[0], sp, envp);
	return (0);
}

/*
1 fichier infile
2 fichier outfile
lancer pipex infile outfile1
lancer command infile outfile2
lancer diff outfile1 outfile2


*/