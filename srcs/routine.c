/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:00:19 by pleblond          #+#    #+#             */
/*   Updated: 2025/05/02 23:34:38 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

bool	philo_died(t_philo *philo)
{
	bool	dead;

	pthread_mutex_lock(philo->dead_lock);
	dead = philo->dead;
	pthread_mutex_unlock(philo->dead_lock);
	return (dead);
}

void	philo_routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	if (philos->id % 2 == 0)
		ft_usleep(NULL, 1);
	while (philo_died(philos) == false)
	{
		philo_eat(philos);
		philo_sleep(philos);
		philo_think(philos);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_philo *philos;

	philos = (t_philo *)arg;
	while (1)
		if (check_philos_dead(philos) || check_philos_all_ate(philos))
			break ;
		return (NULL);
}