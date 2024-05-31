/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:58:46 by gfinet            #+#    #+#             */
/*   Updated: 2024/05/31 21:35:38 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	take_fork_lr(t_philo *phi, t_philo_data *d, int l_r)
{
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
	*hand = 1;
	pthread_mutex_lock(mut_fork);
	d->forks[fork] = 1;
	printf("\033[0;33m%ld  %d has taken a fork\n\033[0m",
		get_time(d->time_zero), phi->num);
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

	pthread_mutex_lock(&d->eat[phi->num - 1]);
	phi->nb_diner++;
	printf("\033[0;32m%ld  %d is eating\n\033[0m",
		get_time(d->time_zero), phi->num);
	phi->has_eat = 1;
	pthread_mutex_unlock(&d->eat[phi->num - 1]);
	pthread_mutex_lock(&d->time[phi->num - 1]);
	phi->time = get_time(0);
	pthread_mutex_unlock(&d->time[phi->num - 1]);
	time = get_time(0) + d->eat_time;
	while (get_time(0) < time)
		usleep(100);
}

void	sleep_time(t_philo *phi, t_philo_data *data)
{
	long	time;

	phi->has_eat = 0;
	if (!is_philo_dead(data))
		printf("\033[0;35m%ld  %d is sleeping\n\033[0m",
			get_time(data->time_zero), phi->num);
	time = get_time(0);
	while (get_time(0) < time + data->sleep_time)
		usleep(100);
	if (!is_philo_dead(data))
		printf("\033[0;34m%ld  %d is thinking\n\033[0m",
			get_time(data->time_zero), phi->num);
}

void	choose_forks(t_philo *phi)
{
	if (!(phi->num % 2))
	{
		take_fork_lr(phi, phi->arg, 0);
		take_fork_lr(phi, phi->arg, 1);
	}
	else
	{
		usleep(100);
		take_fork_lr(phi, phi->arg, 1);
		take_fork_lr(phi, phi->arg, 0);
	}
}
