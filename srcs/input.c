/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 12:53:31 by pleblond          #+#    #+#             */
/*   Updated: 2025/05/07 12:53:31 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static bool	is_arg_count_valid(int argc)
{
	return (argc == 5 || argc == 6);
}

static bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static bool	is_numb(char *str)
{
	if (is_digit(*str) == true || *str == '+' || *str == '-')
		str++;
	else
		return (false);
	while (*str)
		if (is_digit(*str++) == false)
			return (false);
	return (true);
}

static bool	is_valid_philo_cfg(int num, int index)
{
	if (index == 1 && !(num > 0 && num <= PHILO_MAX))
		return (print_error(INV_NUM_PHILOS), false);
	if (index == 2 && !(num > 0 && num <= MAX_VAL))
		return (print_error(INV_TIME_DIE), false);
	if (index == 3 && !(num > 0 && num <= MAX_VAL))
		return (print_error(INV_TIME_EAT), false);
	if (index == 4 && !(num > 0 && num <= MAX_VAL))
		return (print_error(INV_TIME_SLEEP), false);
	if (index == 5 && !(num > 0 && num <= MAX_VAL))
		return (print_error(INV_NUM_MEALS), false);
	return (true);
}

bool	are_args_valid(int argc, char **argv)
{
	int		i;

	if (is_arg_count_valid(argc) == false)
		return (print_error(INV_NUM_ARGS USAGE), false);
	i = 1;
	while (i < argc)
	{
		if (is_numb(argv[i] == false))
			return (print_error(INV_NUM USAGE), false);
		if (is_valid_philo_cfg(ft_atoi(argv[i]), i) == false)
			return (false);
		i++;
	}
	return (true);
}
