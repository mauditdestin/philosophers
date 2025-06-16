/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:08:55 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/16 13:19:01 by pleblond         ###   ########.fr       */
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
	
}

void	init_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks, char **argv)
{

}