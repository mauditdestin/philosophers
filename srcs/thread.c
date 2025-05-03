/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:00:23 by pleblond          #+#    #+#             */
/*   Updated: 2025/05/03 20:26:17 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	manage_threads(t_philo *philos)
{
	int			i;
	int			num_of_philos;
	pthread_t	monitor;

	pthread_create(&monitor, NULL, monitor_routine, (void *)philos);
	i = 0;
	num_of_philos = philos->num_of_philos;
	while (i < num_of_philos)
	{
		pthread_create(&philos[i].thread, NULL, philo_routine,
				(void *)&philos[i]);
		i++;
	}
	pthread_join(monitor, NULL);
	i = 0;
	while (i < num_of_philos)
		pthread_join(philos[i++].thread, NULL);
}