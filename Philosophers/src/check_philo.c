/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:23:11 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/18 17:33:40 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	my_sleep(long duration)
{
	long	time;

	time = get_time(0) + duration;
	while (get_time(0) < time)
		usleep(100);
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
	int	t;
	int	i;

	i = 0;
	while (i < d->nb_philo && !d->is_dead && !has_eaten_enough(d->philos))
	{
		t = (get_time(d->philos[i].time) > d->die_time);
		if (t)
		{
			d->is_dead = 1;
			printf("\033[0;31m%ld  %d died\n\033[0m", get_time(d->time_zero),
				d->philos[i].num);
		}
		i++;
		i = i % d->nb_philo;
	}
	i = 0;
	while (i < d->nb_philo)
		pthread_mutex_unlock(&d->fork[i++]);
	return (0);
}
