/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:54:00 by Gfinet            #+#    #+#             */
/*   Updated: 2024/03/18 17:45:06 by gfinet           ###   ########.fr       */
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
static int	philo_init(philo_t *data,char **arg)
{
	data->arg.nb_philo = ft_atoi(arg[0]);
	data->arg.die_time = ft_atoi(arg[1]);
	data->arg.eat_time = ft_atoi(arg[2]);
	data->arg.sleep_time = ft_atoi(arg[3]);
	printf("%d %d %d %d\n", data->arg.nb_philo, data->arg.die_time, data->arg.eat_time, data->arg.sleep_time);
	if (arg[4])
		data->arg.nb_diner = ft_atoi(arg[4]);
	data->fourchettes = malloc(sizeof(int) * data->arg.nb_philo);
	if (!data->fourchettes)
		return (0);
	data->philo = malloc(sizeof(pthread_t) * data->arg.nb_philo);
	if (!data->philo)
		return (free(data->fourchettes), 0);
	data->mutex = malloc(sizeof(pthread_mutex_t) * data->arg.nb_philo);
	if (!data->mutex)
		return (free(data->fourchettes), free(data->philo), 0);
	return (1);
}
void *philosophers(void *data)
{
	wich_p_t *d;
	philo_t *p;
	int num;

	d = (wich_p_t *)data;
	num = d->num_philo; 
	p = d->data;
	printf("thread %d créé\n", num);
	printf("coucou %p - %p\n", p->philo[num], pthread_self());
	while (1)
	{
		if (1)
			break;
	}
	usleep(p->arg.sleep_time * 10);
	return (0);
}

// ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
int main(int argc, char **argv)
{
	int		i;
	wich_p_t p;
	philo_t data;

	if (argc < 5)
		return (printf("Not enough arg\n"), 0);
	else
	{
		i = 0;
		p.data = &data;
		if (!check_arg(argv + 1))
			return (printf("Bad arg\n"), 0);
		philo_init(&data, argv +1);
		while (i < data.arg.nb_philo)
		{
			p.num_philo = i + 1;
			pthread_mutex_init(&data.mutex[i], 0);
			pthread_create(&data.philo[i], 0, philosophers, &p);
			i++;
			usleep(5);
		}
		free(data.fourchettes);
		free(data.philo);
		free(data.mutex);
	}
	//system("leaks philo");
	usleep(6000);
	printf("hello\n");
	return (0);
}
