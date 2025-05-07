/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:58:55 by pleblond          #+#    #+#             */
/*   Updated: 2025/05/07 12:52:26 by pleblond         ###   ########.fr       */
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

# define TAKE_FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5


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
int		ft_usleep(t_philo *philo, size_t ms);
void	print_behaviour(t_philo *philo, int behaviour);

// ROUTINE
void	*monitor_routine(void *arg);
void	philo_routine(void *arg);
bool	philo_died(t_philo *philo);

// INPUT


// INPUT_UTILS
int		ft_atoi(char *str);

// INIT
void	init_prog(t_program *prog, t_philo *philo);

// THREAD
void	manage_threads(t_philo *philos);

// BEHAVIOUR
void	philo_sleep(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_die(t_philo *philo);