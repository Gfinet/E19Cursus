/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:54:00 by Gfinet            #+#    #+#             */
/*   Updated: 2024/04/04 02:05:41 by Gfinet           ###   ########.fr       */
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
		if (!d->forks[phi->l_fork] && !d->forks[phi->r_fork])
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

int	main(int argc, char **argv)
{
	int				i;
	t_philo_data	data;
	t_philo			*philos;

	if (argc < 5)
		return (printf("Not enough arg\n"), 0);
	else
	{
		if (!check_arg(argv + 1))
			return (printf("Bad arg\n"), 0);
		if (!init_all(&philos, &data, argc, argv))
			return (0);
		i = -1;
		while (++i < data.nb_philo)
			pthread_create(&philos[i].thread, 0, philosophers, &philos[i]);
		while (!data.is_dead && !has_eaten_enough(philos))
			i = 0;
		while (i < data.nb_philo)
			if (!pthread_join(philos[i].thread, 0))
				i++;
		free(philos);
		free(data.forks);
		free(data.fork);
	}
	//system("leaks philo");
	return (0);
}
