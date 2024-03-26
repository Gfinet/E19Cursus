/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:54:00 by Gfinet            #+#    #+#             */
/*   Updated: 2024/03/26 18:33:06 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long	trad_time(struct timeval tv)
{
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long	get_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, 0);
	return (trad_time(tv));
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

static philo_t	*philo_init(philo_t *philos, philo_data_t *data, char **arg)
{
	int	i;
	data->nb_philo = ft_atol(arg[0]);
	data->die_time = ft_atol(arg[1]);
	data->eat_time = ft_atol(arg[2]);
	data->sleep_time = ft_atol(arg[3]);
	philos = malloc(sizeof(philo_t) * data->nb_philo);
	if (!philos)
		return (0);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork)
		return (free(philos), NULL);
	data->nb_diner = -1;
	if (arg[4])
		data->nb_diner = ft_atoi(arg[4]);
	data->forks = malloc(sizeof(int) * data->nb_philo);
	if (!data->forks)
		return (free(philos), free(data->fork), NULL);
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
		i++;
	}
	return (philos);
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
	int err;

	phi = (philo_t *)data;
	d = phi->arg;
	d->time_zero = get_time();
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
	while (get_time() - phi->time < d->die_time && (d->nb_diner < 0 || phi->nb_diner < d->nb_diner)) // && tv.tv_usec < 300000)
	{
		err = pthread_mutex_lock(&phi->arg->fork[phi->l_fork]);
		if (!err)
		{
			d->forks[phi->l_fork] = 1;
			phi->l_hand = 1;
			printf("%ld  %d took L fork (%d)\n", get_time() - d->time_zero, phi->num, phi->l_fork);
		}
		err = pthread_mutex_lock(&phi->arg->fork[phi->r_fork]);
		if (!err)
		{
			d->forks[phi->r_fork] = 1;
			phi->r_hand = 1;
			printf("%ld  %d took R fork (%d)\n", get_time() - d->time_zero, phi->num, phi->r_fork);
		}
		if (phi->l_hand && phi->r_hand)
		{
			printf("%ld  %d eat %d\n", get_time() - d->time_zero, phi->num, phi->nb_diner);
			usleep(d->eat_time);
			phi->has_eat = 1;
		}
		if (phi->l_hand)
		{
			d->forks[phi->l_fork] = 0;
			pthread_mutex_unlock(&phi->arg->fork[phi->l_fork]);
			phi->l_hand = 0;
			printf("%ld  %d let  L fork (%d)\n", get_time() - d->time_zero, phi->num, phi->l_fork);
		}
		if (phi->r_hand)
		{
			d->forks[phi->r_fork] = 0;
			pthread_mutex_unlock(&phi->arg->fork[phi->r_fork]);
			phi->r_hand = 0;
			printf("%ld  %d let  R fork (%d)\n", get_time() - d->time_zero, phi->num, phi->r_fork);
		}
		if (phi->has_eat)
		{
			printf("%ld  %d sleep\n", get_time() - d->time_zero, phi->num);
			usleep(d->sleep_time);
			phi->has_eat = 0;
			phi->nb_diner++;
			phi->time = get_time();
		}
	}
	if (phi->nb_diner < phi->arg->nb_diner && phi->time >= d->die_time)
		printf("%ld  %d is ded----------------------------------------\n", get_time(), phi->num);
	printf("%ld philo %d has eaten %d times\n", get_time()- d->time_zero, phi->num, phi->nb_diner);
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
