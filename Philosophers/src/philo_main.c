/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:54:00 by Gfinet            #+#    #+#             */
/*   Updated: 2024/03/20 14:33:50 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
		if (ft_atoi(arg[i]) <= 0)
			return(0);
		i++;
	}
	return (1);
}
static philo_t	*philo_init(philo_t *philos, philo_data_t *data, char **arg)
{
	int	i;
	data->nb_philo = ft_atoi(arg[0]);
	data->die_time = ft_atoi(arg[1]);
	data->eat_time = ft_atoi(arg[2]);
	data->sleep_time = ft_atoi(arg[3]);
	philos = malloc(sizeof(philo_t) * data->nb_philo);
	if (!philos)
		return (0);
	printf("%d %d %d %d\n", data->nb_philo, data->die_time, data->eat_time, data->sleep_time);
	data->nb_diner = -1;
	if (arg[4])
		data->nb_diner = ft_atoi(arg[4]);
	data->fourchettes = malloc(sizeof(int) * data->nb_philo);
	if (!data->fourchettes)
		return (free(philos), NULL);
	i = 0;
	while (i < data->nb_philo)
	{
		philos[i].arg = data;
		philos[i].num = i + 1;
		i++;
	}
	return (philos);
}
void *philosophers(void *data)
{
	philo_data_t *d;
	philo_t *phi;

	phi = (philo_t *)data;
	d = phi->arg;
	printf("thread %d créé\n", phi->num);
	printf("thread : %p\nself   : %p\n", phi->thread, pthread_self());
	while (1)
	{
		if (1)
			break;
	}
	return (0);
}

// ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
int main(int argc, char **argv)
{
	int				i;
	philo_data_t	data;
	philo_t			*philos;

	if (argc < 5)
		return (printf("Not enough arg\n"), 0);
	else
	{
		i = 0;
		philos = 0;
		if (!check_arg(argv + 1))
			return (printf("Bad arg\n"), 0);
		philos = philo_init(philos, &data, argv +1);
		while (i < data.nb_philo)
		{
			//pthread_mutex_init(&philos[i].mutex, 0);
			pthread_create(&philos[i].thread, 0, philosophers, &philos[i]);
			i++;
			usleep(5);
		}
		free(data.fourchettes);
		free(philos);
	}
	system("leaks philo");
	usleep(6000);
	printf("hello\n");
	return (0);
}
