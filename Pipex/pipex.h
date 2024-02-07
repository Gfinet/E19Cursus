/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:22:48 by gfinet            #+#    #+#             */
/*   Updated: 2024/02/06 23:53:30 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# include "Printf/ft_printf.h"

typedef struct s_cmds
{
	char	***arg;
	char	**path;
	char	**cmd_arg;
	int		nb_pr;
}	t_cmds;

char	*find_path(char ***command, char **path, char *arg, char *infile);
void	launch_cmd(t_cmds *c, int pipe_fd[], char **envp, int pr);
int		pipex(t_cmds *c, pid_t *proc, int pipe_fd[], char **envp);
int		split_cmd(char ***command, char *infile, char *arg);
int		find_all_path(t_cmds *c, char **argv, int nb_pr);
int		init_t_cmds(t_cmds *c, int argc, char **envp);
int		end(t_cmds *c, int write_fd, char **envp);
int		write_file(int read_fd, int write_fd);
void	free_t_cmd(t_cmds *c);
void	send_error(int flag);

#endif