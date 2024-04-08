/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:58:46 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/05 22:43:37 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	take_fork_lr(t_philo *phi, t_philo_data *d, int l_r)
{
	int				err;
	int				fork;
	int				*hand;
	pthread_mutex_t	*mut_fork;

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
		printf("%ld  %d has taken a fork\n", get_time(d->time_zero), phi->num);
	}
}

void	let_fork_lr(t_philo *phi, t_philo_data *data, int l_r)
{
	int				fork;
	int				*hand;
	pthread_mutex_t	*mut_fork;

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
}

void	eat_time(t_philo *phi, t_philo_data *d)
{
	long	time;

	pthread_mutex_lock(&d->dead);
	phi->nb_diner++;
	if (!d->is_dead)
		printf("%ld  %d is eating\n", get_time(d->time_zero), phi->num);
	pthread_mutex_unlock(&d->dead);
	phi->has_eat = 1;
	phi->time = get_time(0);
	time = get_time(0);
	while (get_time(0) < time + d->eat_time)
		usleep(500);
}

void	sleep_time(t_philo *phi, t_philo_data *data)
{
	long	time;

	pthread_mutex_lock(&data->dead);
	phi->has_eat = 0;
	if (!data->is_dead)
		printf("%ld  %d is sleeping\n", get_time(data->time_zero), phi->num);
	pthread_mutex_unlock(&data->dead);
	time = get_time(0);
	while (get_time(0) < time + data->sleep_time)
		usleep(500);
	pthread_mutex_lock(&data->dead);
	if (!data->is_dead)
		printf("%ld  %d is thinking\n", get_time(data->time_zero), phi->num);
	pthread_mutex_unlock(&data->dead);
}

void	die_time(t_philo *phi, t_philo_data *d)
{
	if (get_time(phi->time) >= d->die_time && !d->is_dead)
	{
		printf("%ld  %d is ded---\n", get_time(d->time_zero), phi->num);
		pthread_mutex_lock(&(d->dead));
		phi->is_dead = 1;
		d->is_dead = 1;
		pthread_mutex_unlock(&(d->dead));
	}
}
