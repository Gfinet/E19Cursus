/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:45:44 by gfinet            #+#    #+#             */
/*   Updated: 2024/05/20 22:29:25 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_fork(t_philo_data *d, int ind)
{
	int	res;

	res = 0;
	pthread_mutex_lock(&d->fork[ind]);
	res = d->forks[ind];
	pthread_mutex_unlock(&d->fork[ind]);
	return (res);
}

void	choose_forks(t_philo *phi)
{
	if (phi->num % 2)
	{
		take_fork_lr(phi, phi->arg, 0);
		if (!check_fork(phi->arg, phi->r_fork))
			take_fork_lr(phi, phi->arg, 1);
	}
	else
	{
		take_fork_lr(phi, phi->arg, 1);
		if (!check_fork(phi->arg, phi->l_fork))
			take_fork_lr(phi, phi->arg, 0);
	}
}

int	is_dead(t_philo *phi, t_philo_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (phi->is_dead)
			return (0);
		i++;
	}
	return (1);
}

int	has_eaten_enough(t_philo *phi)
{
	int	i;

	i = 0;
	if (phi->arg->nb_diner < 0)
		return (0);
	while (i < phi->arg->nb_philo)
	{
		pthread_mutex_lock(&phi->arg->eat);
		if (phi[i].nb_diner < phi->arg->nb_diner)
			return (pthread_mutex_unlock(&phi->arg->eat), 0);
		pthread_mutex_unlock(&phi->arg->eat);
		i++;
	}
	return (1);
}

int	check_end(t_philo_data *d)
{
	int	t;
	int	i;

	i = 0;
	t = 0;
	while (i < d->nb_philo && !is_philo_dead(d) && !has_eaten_enough(d->philos))
	{
		pthread_mutex_lock(&d->time);
		t = (get_time(d->philos[i].time) >= d->die_time);
		pthread_mutex_unlock(&d->time);
		if (t)
		{
			printf("\033[0;33m%ld  %d died\n\033[0m", get_time(d->time_zero),
				d->philos[i].num);
			pthread_mutex_lock(&(d->dead));
			d->is_dead = 1;
			pthread_mutex_unlock(&(d->dead));
		}
		i++;
		i = i % d->nb_philo;
	}
	return (0);
}
