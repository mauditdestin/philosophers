/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:59:41 by pleblond          #+#    #+#             */
/*   Updated: 2025/05/01 13:59:41 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static size_t ft_strlen(char *str)
{
	size_t	i;
	
	i = 0;
	while(*str++);
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