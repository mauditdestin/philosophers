/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:58:55 by pleblond          #+#    #+#             */
/*   Updated: 2025/05/01 13:58:55 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

# define PHILO_MAX 200
# define MAX_VAL 2147483647


typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				num_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_times_of_eat;
	pthread_mutex_t	*dead_lock;
	bool			dead;
}	t_philo;

typedef struct s_program
{
	t_philo	*philos;
}	t_program;


// PHILO_UTILS
void	print_error(char *err);
size_t	get_current_time(void);

// ROUTINE
void	*monitor_routine(void *arg);
void	philo_routine(void *arg);