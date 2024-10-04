/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:30:22 by sennakhl          #+#    #+#             */
/*   Updated: 2024/10/04 16:04:16 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_diff_time(long start)
{
	struct timeval	curnt;
	long			diff;

	gettimeofday(&curnt, NULL);
	diff = curnt.tv_sec * 1000 + curnt.tv_usec / 1000;
	diff -= start;
	return (diff);
}

void	ft_eating(t_philo *philo, long start)
{
	struct timeval	crnt;
	long	diff;

	gettimeofday(&crnt, NULL);
	diff = get_diff_time(start);
	philo->l_eat = crnt.tv_sec * 1000 + crnt.tv_usec / 1000;
	pthread_mutex_lock(&philo->all->mutex);
	philo->all->forks++;
	pthread_mutex_unlock(&philo->all->mutex);
	if (philo->all->die)
	{
		printf("%ld %d has taken a fork\n", diff, philo->n);
		printf("%ld %d has taken a fork\n", diff, philo->n);
		printf("%ld %d is eating\n", diff, philo->n);
	}
	philo->n_eat += 1;
	usleep(philo->all->t_eat * 1000);
	philo->all->forks--;
}

int	ft_last(t_philo *philo, long start)
{
	if (!philo->n_eat)
		usleep(philo->all->t_eat * 2000);
	else if (philo->all->n_philo % 2 && philo->all->t_sleep <= 2
		* philo->all->t_eat)
		usleep((2 * philo->all->t_eat - philo->all->t_sleep) * 1000);
	return (main_routine(philo, start));
}

int	ft_even(t_philo *philo, long start)
{
	if (!philo->n_eat)
		usleep(philo->all->t_eat * 1000);
	else if (philo->all->n_philo % 2 && philo->all->t_sleep < 2
		* philo->all->t_eat)
		usleep((2 * philo->all->t_eat - philo->all->t_sleep) * 1000);
	return (main_routine(philo, start));
}

int	ft_odd(t_philo *philo, long start)
{
	if (philo->n_eat && philo->all->n_philo % 2 && philo->all->t_sleep < 2
		* philo->all->t_eat)
		usleep((2 * philo->all->t_eat - philo->all->t_sleep) * 1000);
	return (main_routine(philo, start));
}
