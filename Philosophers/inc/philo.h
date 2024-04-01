/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:54:49 by Gfinet            #+#    #+#             */
/*   Updated: 2024/04/01 22:42:14 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct philo_data_s
{
	pthread_mutex_t		*fork;
	int		*forks;
	long	nb_philo;
	long	die_time;
	long	sleep_time;
	long	eat_time;
	int		nb_diner;
	long	time_zero;
}	philo_data_t;


typedef struct philo_s
{
	int					num;
	int					l_fork;
	int					r_fork;
	int					l_hand;
	int					r_hand;
	int					has_eat;
	int					nb_diner;
	int					is_dead;
	long				time;
	pthread_t			thread;
	philo_data_t		*arg;
	pthread_mutex_t		mutex;
}	philo_t;

//main_philo.c
long	get_time(long start);
long	trad_time(struct timeval tv);

//philo_init.c
int *data_init(philo_data_t *d, int argc, char **arg);
philo_t	*philo_init(philo_t *philos, philo_data_t *data, char **arg);

//utils.c
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

//action.c
void take_fork_lr(philo_t *phi, philo_data_t *data, int l_r);
void eat_time(philo_t *phi, philo_data_t *d);
void let_fork_lr(philo_t *phi, philo_data_t *data, int l_r);
void sleep_time(philo_t *phi, philo_data_t *data);
#endif