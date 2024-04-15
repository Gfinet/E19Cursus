/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:54:00 by Gfinet            #+#    #+#             */
/*   Updated: 2024/04/15 22:29:15 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	check_arg(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (!ft_isdigit(arg[i][j]))
				return (0);
			j++;
		}
		if (ft_atol(arg[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

void	free_all_philo(t_philo *philos, t_philo_data *d)
{
	int	i;

	i = 0;
	if (d->fork)
	{
		while (i < d->nb_philo)
			pthread_mutex_destroy(&d->fork[i++]);
		free(d->fork);
	}
	pthread_mutex_destroy(&d->dead);
	pthread_mutex_destroy(&d->eat);
	pthread_mutex_destroy(&d->time);
	if (d->forks)
		free(d->forks);
	if (philos)
		free(philos);
}

void	*philosophers(void *data)
{
	t_philo_data	*d;
	t_philo			*phi;

	phi = (t_philo *)data;
	d = phi->arg;
	phi->time = d->time_zero;
	while (!is_philo_dead(d))
	{
		if (phi->l_hand && phi->r_hand)
			eat_time(phi, d);
		if (phi->l_hand && !is_philo_dead(d))
			let_fork_lr(phi, d, 0);
		if (phi->r_hand && !is_philo_dead(d))
			let_fork_lr(phi, d, 1);
		if (phi->has_eat && !is_philo_dead(d))
			sleep_time(phi, d);
		if (get_time(phi->time) < d->die_time && !is_philo_dead(d))
			choose_forks(phi);
	}
	if (phi->l_hand)
		pthread_mutex_unlock(&d->fork[phi->l_hand]);
	if (phi->r_hand)
		pthread_mutex_unlock(&d->fork[phi->r_hand]);
	return (0);
}

int	main(int argc, char **argv)
{
	int				i;
	t_philo_data	data;
	t_philo			*philos;

	if (argc >= 5)
	{
		if (!check_arg(argv + 1))
			return (printf("Bad arg\n"), 0);
		if (!init_all(&philos, &data, argc, argv))
			return (0);
		i = -1;
		while (++i < data.nb_philo)
			pthread_create(&philos[i].thread, 0, philosophers, &philos[i]);
		if (check_end(&data))
			i = 0;
		while (i < data.nb_philo)
			if (!pthread_join(philos[i].thread, 0))
				i++;
		free_all_philo(philos, &data);
	}
	else
		return (printf("Not enough arg\n"), 0);
	return (0);
}
