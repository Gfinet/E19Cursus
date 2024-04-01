/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:58:46 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/01 22:28:58 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void take_fork_lr(philo_t *phi, philo_data_t *data, int l_r)
{
	int err;
	int fork;
	int *hand;
	pthread_mutex_t *mut_fork;

	hand = &phi->r_hand;
	fork = phi->r_fork;
	mut_fork = &data->fork[phi->r_fork];
	if (!l_r)
	{
		fork = phi->l_fork;
		mut_fork = &data->fork[phi->l_fork];
		hand = &phi->l_hand;
	}
	err = pthread_mutex_lock(mut_fork);
	if (!err)
	{
		data->forks[fork] = 1;
		*hand = 1;
		printf("%ld  %d took ",get_time(data->time_zero), phi->num);
		if (!l_r)
			printf("L ");
		else
			printf("R ");
		printf("fork (%d)\n", fork);
	}
}

/*
err = pthread_mutex_lock(&d->fork[phi->r_fork]);
if (!err)
{
	d->forks[phi->r_fork] = 1;
	phi->r_hand = 1;
	printf("%ld  %d took R fork (%d)\n", get_time(d->time_zero), phi->num, phi->r_fork);
}
if (phi->l_hand && phi->r_hand)
{
	printf("%ld  %d eat %d\n", get_time(d->time_zero), phi->num, phi->nb_diner);
	usleep(d->eat_time);
	phi->has_eat = 1;
}
*/

void let_fork_lr(philo_t *phi, philo_data_t *data, int l_r)
{
	int fork;
	int *hand;
	pthread_mutex_t *mut_fork;

	hand = &phi->r_hand;
	fork = phi->r_fork;
	mut_fork = &data->fork[phi->r_fork];
	if (!l_r)
	{
		fork = phi->l_fork;
		mut_fork = &data->fork[phi->l_fork];
		hand = &phi->l_hand;
	}
	data->forks[fork] = 0;
	pthread_mutex_unlock(mut_fork);
	*hand = 0;
	printf("%ld  %d let  ", get_time(data->time_zero), phi->num);
	if (!l_r)
		printf("L ");
	else
		printf("R ");
	printf("fork (%d)\n", fork);
}

void eat_time(philo_t *phi, philo_data_t *d)
{
	printf("%ld  %d eat %d\n", get_time(d->time_zero), phi->num, phi->nb_diner);
	usleep(d->eat_time);
	phi->has_eat = 1;
}

void sleep_time(philo_t *phi, philo_data_t *data)
{
	printf("%ld  %d sleep\n", get_time(data->time_zero), phi->num);
	usleep(data->sleep_time);
	phi->has_eat = 0;
	phi->nb_diner++;
	phi->time = get_time(0);
}