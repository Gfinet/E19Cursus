/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:58:46 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/18 17:32:58 by gfinet           ###   ########.fr       */
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
	if (d->is_dead)
		return ;
	pthread_mutex_lock(mut_fork);
	*hand = 1;
	d->forks[fork] = 1;
	if (!d->is_dead)
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
	*hand = 0;
	pthread_mutex_unlock(mut_fork);
}

void	eat_time(t_philo *phi, t_philo_data *d)
{
	phi->nb_diner++;
	printf("\033[0;32m%ld  %d is eating\n\033[0m",
		get_time(d->time_zero), phi->num);
	phi->has_eat = 1;
	phi->time = get_time(0);
	my_sleep(d->eat_time);
}

void	sleep_time(t_philo *phi, t_philo_data *data)
{
	phi->has_eat = 0;
	if (!data->is_dead)
		printf("\033[0;35m%ld  %d is sleeping\n\033[0m",
			get_time(data->time_zero), phi->num);
	my_sleep(data->sleep_time);
	if (!data->is_dead)
		printf("\033[0;34m%ld  %d is thinking\n\033[0m",
			get_time(data->time_zero), phi->num);
}

void	choose_forks(t_philo *phi)
{
	if (!(phi->num % 2))
	{
		if (!phi->arg->is_dead)
			take_fork_lr(phi, phi->arg, 0);
		if (!phi->arg->is_dead)
			take_fork_lr(phi, phi->arg, 1);
	}
	else
	{
		if (!phi->arg->is_dead)
			take_fork_lr(phi, phi->arg, 1);
		if (!phi->arg->is_dead)
			take_fork_lr(phi, phi->arg, 0);
	}
}
