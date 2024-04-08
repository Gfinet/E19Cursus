/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:45:44 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/08 14:56:49 by gfinet           ###   ########.fr       */
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
		if (!check_fork(phi->arg, phi->l_hand)
			&& !check_fork(phi->arg, phi->r_hand))
		{
			take_fork_lr(phi, phi->arg, 0);
			take_fork_lr(phi, phi->arg, 1);
		}
	}
	else
	{
		if (!check_fork(phi->arg, phi->r_hand)
			&& !check_fork(phi->arg, phi->l_hand))
		{
			take_fork_lr(phi, phi->arg, 1);
			take_fork_lr(phi, phi->arg, 0);
		}
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
