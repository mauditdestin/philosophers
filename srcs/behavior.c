/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:00:13 by pleblond          #+#    #+#             */
/*   Updated: 2025/05/03 20:30:18 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	philo_sleep(t_philo *philo)
{
	print_behavior(philo, SLEEP);
	ft_usleep(philo, philo->time_to_sleep);
}

void	philo_eat(t_philo *philo)
{
	
}

void	philo_think(t_philo *philo)
{
	print_behavior(philo, THINK);
}

void	philo_die(t_philo *philo)
{
	print_behavior(philo, DIE);
}