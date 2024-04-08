/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:45:44 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/05 22:47:32 by gfinet           ###   ########.fr       */
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

void	*philosophers(void *data)
{
	t_philo_data	*d;
	t_philo			*phi;

	phi = (t_philo *)data;
	d = phi->arg;
	phi->time = d->time_zero;
	while (get_time(phi->time) < d->die_time && (d->nb_diner < 0
			|| phi->nb_diner < d->nb_diner) && !d->is_dead)
	{
		if (!check_fork(d, phi->l_hand) && !check_fork(d, phi->r_hand))
		{
			take_fork_lr(phi, d, 0);
			take_fork_lr(phi, d, 1);
		}
		if (phi->l_hand && phi->r_hand)
			eat_time(phi, d);
		if (phi->l_hand)
			let_fork_lr(phi, d, 0);
		if (phi->r_hand)
			let_fork_lr(phi, d, 1);
		if (phi->has_eat)
			sleep_time(phi, d);
	}
	die_time(phi, d);
	return (0);
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
		if (phi[i].nb_diner < phi->arg->nb_diner)
			return (0);
		i++;
	}
	return (1);
}

int	check_end(t_philo_data *d)
{
	int	res;

	pthread_mutex_lock(&d->dead);
	res = d->is_dead + has_eaten_enough(d->philos);
	pthread_mutex_unlock(&d->dead);
	return (res);
}
