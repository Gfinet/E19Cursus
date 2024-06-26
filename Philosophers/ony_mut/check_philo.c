/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:23:11 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/03 19:44:02 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	check_fork(t_philo *phi, t_philo_data *d, int ind)
{
	int	res;

	res = 0;
	pthread_mutex_lock(&d->eat[ind]);
	pthread_mutex_lock(&d->eat[phi->num - 1]);
	res = (phi->nb_diner >= d->philos[ind].nb_diner);
	pthread_mutex_unlock(&d->eat[phi->num - 1]);
	pthread_mutex_unlock(&d->eat[ind]);
	return (res);
}

int	is_philo_dead(t_philo_data *d)
{
	int	dead;

	pthread_mutex_lock(&d->dead);
	dead = d->is_dead;
	pthread_mutex_unlock(&d->dead);
	return (dead);
}

int	has_eaten_enough(t_philo *phi)
{
	int	i;

	i = 0;
	if (phi->arg->nb_diner < 0)
		return (0);
	while (i < phi->arg->nb_philo)
	{
		pthread_mutex_lock(&phi->arg->eat[i]);
		if (phi[i].nb_diner < phi->arg->nb_diner)
			return (pthread_mutex_unlock(&phi->arg->eat[i]), 0);
		pthread_mutex_unlock(&phi->arg->eat[i]);
		i++;
	}
	return (1);
}

int	check_end(t_philo_data *d)
{
	int	t;
	int	i;

	i = 0;
	while (i < d->nb_philo && !is_philo_dead(d) && !has_eaten_enough(d->philos))
	{
		pthread_mutex_lock(&d->time[i]);
		t = (get_time(d->philos[i].time) >= d->die_time + 1);
		pthread_mutex_unlock(&d->time[i]);
		if (t)
		{
			printf("\033[0;31m%ld  %d died\n\033[0m", get_time(d->time_zero),
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
