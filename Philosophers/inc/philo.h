/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:54:49 by Gfinet            #+#    #+#             */
/*   Updated: 2024/06/18 17:32:27 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdatomic.h>

typedef struct s_philo		t_philo;
typedef struct s_philo_data	t_philo_data;

typedef struct s_philo_data
{
	pthread_mutex_t		*fork;
	atomic_int			is_dead;
	t_philo				*philos;
	int					*forks;
	int					nb_diner;
	long				nb_philo;
	long				die_time;
	long				sleep_time;
	long				eat_time;
	long				time_zero;
}	t_philo_data;

typedef struct s_philo
{
	int					num;
	int					ind;
	int					l_fork;
	int					r_fork;
	int					l_hand;
	int					r_hand;
	int					has_eat;
	atomic_int			nb_diner;
	atomic_long			time;
	pthread_t			thread;
	t_philo_data		*arg;
}	t_philo;

//main_philo.c
int		is_dead(t_philo *phi, t_philo_data *data);
int		has_eaten_enough(t_philo *phi);
void	*philosophers(void *data);

//philo_init.c
int		data_init(t_philo_data *d, int argc, char **arg);
t_philo	*philo_init(t_philo *philos, t_philo_data *data);
void	init_philo_fork(t_philo *phi, t_philo_data *d, int i);
int		init_all(t_philo **philos, t_philo_data *data, int argc, char **argv);
int		is_philo_dead(t_philo_data *d);

//check_philo.c
void	my_sleep(long duration);
int		has_eaten_enough(t_philo *phi);
int		check_end(t_philo_data *d);

//utils.c
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
long	get_time(long start);
long	trad_time(struct timeval tv);

//action.c
void	choose_forks(t_philo *phi);
void	take_fork_lr(t_philo *phi, t_philo_data *data, int l_r);
void	eat_time(t_philo *phi, t_philo_data *d);
void	let_fork_lr(t_philo *phi, t_philo_data *data, int l_r);
void	sleep_time(t_philo *phi, t_philo_data *data);

#endif