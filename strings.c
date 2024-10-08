/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:02:35 by sennakhl          #+#    #+#             */
/*   Updated: 2024/10/08 16:26:11 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo, long start)
{
	long	diff;

	pthread_mutex_lock(&philo->all->mutex);
	diff = get_diff_time(start);
	if (philo->all->die)
		printf("%ld %d is thinking\n", diff, philo->n);
	pthread_mutex_unlock(&philo->all->mutex);
}

long	ft_atoi(char *str)
{
	long	n;
	long	i;

	n = 0;
	i = 0;
	while (str && str[i])
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n);
}
