/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:30:40 by gfinet            #+#    #+#             */
/*   Updated: 2024/05/29 18:17:15 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	data_init(t_philo_data *d, int argc, char **arg)
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
	d->time = malloc(sizeof(pthread_mutex_t) * d->nb_philo);
	if (!d->time)
		return (free(d->fork), 0);
	if (argc == 6)
		d->nb_diner = ft_atoi(arg[4]);
	d->forks = malloc(sizeof(int) * d->nb_philo);
	if (!d->forks)
		return (free(d->fork), free(d->time), 0);
	return (1);
}

t_philo	*philo_init(t_philo *philos, t_philo_data *data)
{
	int	i;

	philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philos)
		return (free(data->fork), free(data->forks), NULL);
	i = 0;
	pthread_mutex_init(&data->dead, 0);
	pthread_mutex_init(&data->eat, 0);
	while (i < data->nb_philo)
	{
		data->forks[i] = 0;
		philos[i].ind = i;
		philos[i].arg = data;
		philos[i].num = i + 1;
		philos[i].l_hand = 0;
		philos[i].r_hand = 0;
		philos[i].has_eat = 0;
		philos[i].is_dead = 0;
		philos[i].nb_diner = 0;
		philos[i].time = get_time(0);
		init_philo_fork(&philos[i], data, i);
		i++;
	}
	return (philos);
}

void	init_philo_fork(t_philo *phi, t_philo_data *d, int i)
{
	pthread_mutex_init(&d->time[i], 0);
	pthread_mutex_init(&d->fork[i], 0);
	phi->l_fork = phi->num - 1;
	phi->r_fork = phi->num % d->nb_philo;
}

int	init_all(t_philo **philos, t_philo_data *data, int argc, char **argv)
{
	if (!data_init(data, argc, argv + 1))
		return (0);
	*philos = philo_init(*philos, data);
	if (!philos)
		return (free(data->fork), free(data->forks), 0);
	data->time_zero = get_time(0);
	data->philos = *philos;
	return (1);
}
