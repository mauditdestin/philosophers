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
	pthread_t	thread;
	int			id;
}	t_philo;

typedef struct s_program
{
	/* data */
}	t_program;


// PHILO_UTILS
void	print_error(char *err);