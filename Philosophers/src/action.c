/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:58:46 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/02 21:42:56 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void take_fork_lr(philo_t *phi, philo_data_t *d, int l_r)
{
	int err;
	int fork;
	int *hand;
	pthread_mutex_t *mut_fork;

	hand = &phi->r_hand;
	fork = phi->r_fork;
	mut_fork = &d->fork[phi->r_fork];
	if (!l_r)
	{
		fork = phi->l_fork;
		mut_fork = &d->fork[phi->l_fork];
		hand = &phi->l_hand;
	}
	err = pthread_mutex_lock(mut_fork);
	if (!err)
	{
		d->forks[fork] = 1;
		*hand = 1;
		//printf("%ld  %d has taken a fork", get_time(d->time_zero), phi->num);
		if (!l_r)
			printf("%ld  %d took L fork (%d)\n",get_time(d->time_zero), 
				phi->num, fork);
		else
			printf("%ld  %d took R fork (%d)\n",get_time(d->time_zero), 
				phi->num, fork);
	}
}

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
	if (!l_r && !data->is_dead)
		printf("%ld  %d let L fork (%d)\n",get_time(data->time_zero), 
			phi->num, fork);
	else if (l_r && !data->is_dead)
		printf("%ld  %d let R fork (%d)\n",get_time(data->time_zero), 
			phi->num, fork);
}

void eat_time(philo_t *phi, philo_data_t *d)
{
	long time;

	phi->nb_diner++;
	if (!d->is_dead)
		printf("%ld  %d eat %d\n", get_time(d->time_zero), phi->num, phi->nb_diner);
	phi->time = get_time(d->time_zero);
	time = get_time(0);
	while (get_time(0) < time + d->eat_time)
		usleep(500);
	phi->has_eat = 1;
}

void sleep_time(philo_t *phi, philo_data_t *data)
{
	long time;
	if (!data->is_dead)
		printf("%ld  %d sleep\n", get_time(data->time_zero), phi->num);
	time = get_time(0);
	while (get_time(0) < time + data->sleep_time)
		usleep(500);
	if (!data->is_dead)
		printf("%ld  %d think\n", get_time(data->time_zero), phi->num);
	phi->has_eat = 0;
}

/*
void
{
	while (time < start + ms)
		usleep(100);
}
*/