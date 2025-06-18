/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:08:55 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/18 16:59:59 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	init_prog(t_program *program, t_philo *philo)
{
	program->dead_flag = false;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	program->philos = philo;
}

void	init_forks(pthread_mutex_t *forks, int num_of_philos)
{
	int	i;
	
	i = 0;
	while (i < num_of_philos)
		pthread_mutex_init(&forks[i++], NULL);
}

static void init_philos_help(t_philo *philo, t_program *program, char **argv)
{
	philo->is_eating = false;
	philo->meals_eaten = 0;
	philo->last_meal = get_current_time();
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->start_time = ft_atoi(argv[4]);
	philo->start_time = get_current_time();
	philo->write_lock = &program->write_lock;
	philo->dead_lock = &program->dead_lock;
	philo->meal_lock = &program->meal_lock;
}

void	init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks, char **argv)
{
	int	i;
	int	num_of_philos;
	
	i = 0;
	num_of_philos = ft_atoi(argv[1]);
	while (i < num_of_philos)
	{
		philos[i].id = i;
		philos[i].num_of_philos = num_of_philos;
		init_philos_help(&philos[i], program, argv);
		if (argv[5] == NULL)
			philos[i].num_times_of_eat = -1;
		else
			philos[i].num_times_of_eat = ft_atoi(argv[5]);
		philos[i].dead = &program->dead_flag;
		philos[i].right_fork = &forks[i];
		if (i == 0)
			philos[i].left_fork = &forks[num_of_philos - 1];
		else
			philos[i].left_fork = &forks[i - 1];
		i++;
	}
}