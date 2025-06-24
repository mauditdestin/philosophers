/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:00:13 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/24 23:57:25 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	philo_sleep(t_philo *philo)
{
	print_behaviour(philo, SLEEP);
	ft_usleep(philo, philo->time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_behaviour(philo, TAKE_FORK);
	if (philo->num_of_philos == 1)
		return (ft_usleep(philo, philo->time_to_die),
			pthread_mutex_unlock(philo->right_fork), (void)0);
	pthread_mutex_lock(philo->left_fork);
	print_behaviour(philo, TAKE_FORK);
	philo->is_eating = true;
	print_behaviour(philo, EAT);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo, philo->time_to_eat);
	philo->is_eating = false;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_think(t_philo *philo)
{
	print_behaviour(philo, THINK);
}

void	philo_die(t_philo *philo)
{
	print_behaviour(philo, DIE);
}