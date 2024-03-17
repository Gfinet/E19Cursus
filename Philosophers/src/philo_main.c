/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:54:00 by Gfinet            #+#    #+#             */
/*   Updated: 2024/03/17 23:25:24 by Gfinet           ###   ########.fr       */
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
static int	philo_init(philo_t *philo,char **arg)
{
	philo->nb_philo = ft_atoi(arg[0]);
	philo->fourchettes = malloc(sizeof(int) * philo->nb_philo);
	if (!philo->fourchettes)
		return (0);
	philo->philo = malloc(sizeof(philosopher_t) * philo->nb_philo);
	if (!philo->philo)
		return (free(philo->fourchettes), 0);
	philo->mutex = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
	if (!philo->mutex)
		return (free(philo->fourchettes), free(philo->philo), 0);
	return (1);
}
void *philosophers(void *data)
{
	philo_t *p;

	p = (philo_t *)data;
	printf("coucou %d\n", p->philo[0].num);
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
	int		i;
	philo_t data;

	if (argc < 5)
		return (printf("Not enough arg\n"), 0);
	else
	{
		i = 0;
		if (!check_arg(argv + 1))
			return (printf("Bad arg\n"), 0);
		philo_init(&data, argv +1);
		while (i < data.nb_philo)
		{
			pthread_mutex_init(&data.mutex[i], 0);
			data.philo[i].num = i + 1;
			pthread_create(&data.philo[i].thread, 0,
				philosophers, &data);
				printf("thread %d créé\n", i + 1);
			i++;
		}
		free(data.fourchettes);
		free(data.philo);
		free(data.mutex);
	}
	return (0);
}
