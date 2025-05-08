/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:00:04 by pleblond          #+#    #+#             */
/*   Updated: 2025/05/07 23:02:34 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void	destroy_all_mutexes(t_program *program, pthread_mutex_t *forks, int num_of_philos)
{
	int	i;
	
	i = 0;
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	while (i < num_of_philos)
		pthread_mutex_destroy(&forks[i++]);
}

int main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t forks[PHILO_MAX];

	if (are_args_valid(argc, argv) == false)
		return (EXIT_FAILURE);
	init_prog(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos();
	manage_threads(philos);
	destroy_all_mutexes(&program, forks, ft_atoi(argv[1]));
	return (EXIT_SUCCESS);
}