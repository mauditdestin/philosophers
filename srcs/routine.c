/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:00:19 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/19 15:22:13 by pleblond         ###   ########.fr       */
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

static bool	check_if_philos_is_dead(t_philo *philos)
{
	int	i;
	int	num_of_philos;

	i = 0;
	num_of_philos = philos->num_of_philos;
	while (i < num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if ((get_current_time() - philos[i].last_meal) >= philos[i].time_to_die && philos[i].is_eating == false)
		{
			pthread_mutex_unlock(philos[i].meal_lock);
			print_behaviour(&philos[i].meal_lock, DIE);
			pthread_mutex_lock(philos->dead_lock);
			*philos->dead = true;
			pthread_mutex_unlock(philos->dead_lock);
			return (true);
		}
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	return (false);
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