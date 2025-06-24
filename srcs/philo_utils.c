/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:59:41 by pleblond          #+#    #+#             */
/*   Updated: 2025/06/24 23:39:32 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static size_t ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while(*str++)
		i++;
	return (i);
}

void	print_error(char *err)
{
	size_t	err_len;

	write(2, "ERROR: ", 7);
	err_len = ft_strlen(err);
	write(2, err, err_len);
}

size_t	get_current_time(void)
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(t_philo *philo, size_t ms)
{
	size_t	start;

	start = get_current_time();
	if (philo != NULL)
		while ((get_current_time() - start) < ms && !philo_died(philo))
			usleep(500);
	else
		while ((get_current_time() - start) < ms)
			usleep(500);
	return (0);
}

void	print_behaviour(t_philo *philo, int behaviour)
{
	pthread_mutex_lock(philo->write_lock);
	if (philo_died(philo) == true)
		return (pthread_mutex_unlock(philo->write_lock), (void)0);
	printf("%ld %d", (get_current_time() - philo->start_time), philo->id);
	if (behaviour == 1)
		printf("has taken a fork\n");
	else if (behaviour == 2)
		printf("is eating\n");
	else if (behaviour == 3)
		printf("is sleeping\n");
	else if (behaviour == 4)
		printf("is thinking\n");
	else if (behaviour == 5)
		printf("died\n");
	pthread_mutex_unlock(philo->write_lock);
}