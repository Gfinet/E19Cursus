/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:54:49 by Gfinet            #+#    #+#             */
/*   Updated: 2024/03/20 13:56:23 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct philo_data_s
{
	int	*fourchettes;
	int	nb_philo;
	int	die_time;
	int	sleep_time;
	int eat_time;
	int nb_diner;
}	philo_data_t;


typedef struct philo_s
{
	int					num;
	pthread_t			thread;
	philo_data_t		*arg;
	pthread_mutex_t		mutex;
}	philo_t;

//utils.c
int	ft_atoi(const char *str);
int	ft_isdigit(int c);

#endif