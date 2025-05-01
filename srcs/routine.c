/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:00:19 by pleblond          #+#    #+#             */
/*   Updated: 2025/05/01 14:00:19 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	*monitor_routine(void *arg)
{
	t_philo *philos;

	philos = (t_philo *)arg;
	while (1)
		if (check_philos_dead(philos) || check_philos_all_ate(philos))
			break ;
		return (NULL);
}