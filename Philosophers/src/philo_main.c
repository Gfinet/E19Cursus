/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:54:00 by Gfinet            #+#    #+#             */
/*   Updated: 2024/04/01 22:42:15 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	trad_time(struct timeval tv)
{
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long	get_time(long start)
{
	struct timeval tv;

	gettimeofday(&tv, 0);
	return (trad_time(tv) - start);
}

static int	check_arg(char **arg)
{
	int i;
	int j;

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
			return(0);
		i++;
	}
	return (1);
}



int is_dead(philo_t *phi)
{
	int i;

	i = 0;
	while (i < phi->arg->nb_philo)
	{
		if (phi[i].time >= phi->arg->die_time)
			return (0);
		i++;
	}
	return (1);
}

int	has_eaten_enough(philo_t *phi)
{
	int i;

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

void *philosophers(void *data)
{
	philo_data_t *d;
	philo_t *phi;

	phi = (philo_t *)data;
	d = phi->arg;
	d->time_zero = get_time(0);
	phi->time = d->time_zero;
	if (phi->num == 1)
		phi->l_fork = d->nb_philo - 1;
	else
		phi->l_fork = phi->num - 2;

	if (phi->num == d->nb_philo)
		phi->r_fork = d->nb_philo - 1;
	else
		phi->r_fork = phi->num - 1;
	//printf("phi %d has l:%d and r:%d\n", phi->num, phi->l_fork, phi->r_fork);
	while (get_time(phi->time) < d->die_time && (d->nb_diner < 0 || phi->nb_diner < d->nb_diner)) // && tv.tv_usec < 300000)
	{
		take_fork_lr(phi, d, 0);
		take_fork_lr(phi, d, 1);
		if (phi->l_hand && phi->r_hand)
			eat_time(phi, d);
		if (phi->l_hand)
			let_fork_lr(phi, d, 0);
		if (phi->r_hand)
			let_fork_lr(phi, d, 1);
		if (phi->has_eat)
			sleep_time(phi, d);
	}
	if (phi->nb_diner < d->nb_diner && phi->time >= d->die_time)
		printf("%ld  %d is ded----------------------------------------\n", get_time(0), phi->num);
	printf("%ld philo %d has eaten %d times\n", get_time(d->time_zero), phi->num, phi->nb_diner);
	phi->is_dead = 1;
	//usleep(6000000);
	return (0);
}

// ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
int main(int argc, char **argv)
{
	int				i;
	philo_data_t	data;
	philo_t			*philos;

	struct timeval tv;
	unsigned long sec;

	if (argc < 5)
		return (printf("Not enough arg\n"), 0);
	else
	{
		sec = 5000000;
		i = 0;
		philos = 0;
		if (!check_arg(argv + 1))
			return (printf("Bad arg\n"), 0);
		if (!data_init(&data, argc, argv + 1))
			return (0);
		philos = philo_init(philos, &data, argv +1);
		gettimeofday(&tv, 0);
		data.time_zero = tv.tv_usec;
		while (i < data.nb_philo)
		{
			pthread_create(&philos[i].thread, 0, philosophers, &philos[i]);
			i++;
		}
		//system("leaks philo");
	gettimeofday(&tv, 0);
	while (!is_dead(philos) && !has_eaten_enough(philos))
	{}
		// free(data.forks);
		// free(philos);
		// free(data.fork);
	}
	
	return (0);
}
