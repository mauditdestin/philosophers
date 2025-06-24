/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:00:19 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/25 00:00:58 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

bool	philo_died(t_philo *philo)
{
	bool	dead;

	pthread_mutex_lock(philo->dead_lock);
	dead = *philo->dead;
	pthread_mutex_unlock(philo->dead_lock);
	return (dead);
}

void	*philo_routine(void *arg)
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
			print_behaviour(&philos[i], DIE);
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

static bool	check_if_philos_all_ate(t_philo *philos)
{
	int	i;
	int	num_of_philos;
	int	num_times_to_eat;

	i = 0;
	num_of_philos = philos->num_of_philos;
	num_times_to_eat = philos->num_times_of_eat;
	if (philos->num_times_of_eat == -1)
		return (false);
	while (i < num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten < num_times_to_eat)
			return (pthread_mutex_unlock(philos[i].meal_lock), false);
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	pthread_mutex_lock(philos->dead_lock);
	*philos->dead = true;
	pthread_mutex_unlock(philos->dead_lock);
	return (true);
}

void	*monitor_routine(void *arg)
{
	t_philo *philos;

	philos = (t_philo *)arg;
	while (1)
		if (check_if_philos_is_dead(philos) || check_if_philos_all_ate(philos))
			break ;
	return (NULL);
}