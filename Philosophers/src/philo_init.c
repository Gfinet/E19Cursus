/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:30:40 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/02 21:20:00 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int data_init(philo_data_t *d, int argc, char **arg)
{
	d->nb_philo = ft_atol(arg[0]);
	d->die_time = ft_atol(arg[1]);
	d->eat_time = ft_atol(arg[2]);
	d->sleep_time = ft_atol(arg[3]);
	d->nb_diner = -1;
	d->is_dead = 0;
	d->fork = malloc(sizeof(pthread_mutex_t) * d->nb_philo);
	if (!d->fork)
		return (0);
	if (argc == 6)
		d->nb_diner = ft_atoi(arg[4]);
	d->forks = malloc(sizeof(int) * d->nb_philo);
	if (!d->forks)
		return (free(d->fork), 0);
	return (1);
}

philo_t	*philo_init(philo_t *philos, philo_data_t *data)
{
	int	i;

	philos = malloc(sizeof(philo_t) * data->nb_philo);
	if (!philos)
		return (free(data->fork), free(data->forks), NULL);
	i = 0;
	while (i < data->nb_philo)
	{
		data->forks[i] = 0;
		philos[i].arg = data;
		philos[i].num = i + 1;
		philos[i].l_hand = 0;
		philos[i].r_hand = 0;
		philos[i].has_eat = 0;
		philos[i].is_dead = 0;
		philos[i].nb_diner = 0;
		pthread_mutex_init(&data->fork[i], 0);
		init_philo_fork(&philos[i], data);
		i++;
	}
	return (philos);
}

void	init_philo_fork(philo_t *phi, philo_data_t *d)
{
	if (phi->num == 1)
		phi->l_fork = d->nb_philo - 1;
	else
		phi->l_fork = phi->num - 2;

	if (phi->num == d->nb_philo)
		phi->r_fork = d->nb_philo - 1;
	else
		phi->r_fork = phi->num - 1;
}