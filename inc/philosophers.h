/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:58:55 by pleblond          #+#    #+#             */
/*   Updated: 2025/05/09 01:33:20 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

// Max numbers of philos to prevent excessive thread and mutex usage.
// Max value for a signed int to avoid integer overflow.
# define PHILO_MAX 200
# define MAX_VAL 2147483647

// ERRORS
# define INV_NUM_ARGS "Invalid number of arguments.\n"
# define INV_NUM "Invalid number.\n"
# define INV_NUM_PHILOS "Invalid number of philosophers.\n"
# define INV_TIME_DIE "Invalid time to die.\n"
# define INV_TIME_EAT "Invalid time to eat.\n"
# define INV_TIME_SLEEP "Invalid time to sleep.\n"
# define INV_NUM_MEALS "Invalid number of times each philosophers must eat.\n"
# define USAGE "Usage: number_of_philosophers time_to_die time_to_eat time_to_sleep \ [number_of_time_each_philosophers_must_eat]\n"

// BEHAVIOUR
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
	int				num_times_of_eat;
	int				meals_eaten;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	size_t			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*meal_lock;
	bool			dead;
	bool			is_eating;
}	t_philo;

typedef struct s_program
{
	t_philo	*philos;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	bool	dead_flag;
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
bool	are_args_valid(int argc, char **argv);

// INPUT_UTILS
int		ft_atoi(char *str);

// INIT
void	init_prog(t_program *prog, t_philo *philo);
void	init_forks(pthread_mutex_t *forks, int num_of_philos);
void	init_philos(t_philo *philos, t_program *program,
						pthread_mutex_t *forks, char **argv);

// THREAD
void	manage_threads(t_philo *philos);

// BEHAVIOUR
void	philo_sleep(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_die(t_philo *philo);