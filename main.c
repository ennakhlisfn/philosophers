/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:20:17 by sennakhl          #+#    #+#             */
/*   Updated: 2024/10/04 16:07:39 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(void)
{
	write(2, "WRONG ARGUMENTS\n", 16);
	return (2);
}

int	main_routine(t_philo *philo, long start)
{
	long	diff;

	while (philo->all->forks == philo->all->n_philo / 2)
		usleep(1);
	diff = get_diff_time(start);
	if (philo->all->die && check_die(philo, diff))
		return (1);
	ft_eating(philo, start);
	diff = get_diff_time(start);
	if (philo->n_eat == philo->all->n_eat)
		return (1);
	if (philo->all->die == 0)
		return (1);
	if (philo->all->die)
		printf("%ld %d is sleeping\n", diff, philo->n);
	usleep(philo->all->t_sleep * 1000);
	diff = get_diff_time(start);
	if (philo->all->n_philo == 0)
		return (1);
	if (philo->all->die)
		printf("%ld %d is thinking\n", diff, philo->n);
	return (0);
}

void	*routine(void *phil)
{
	t_philo			*philo;
	struct timeval	st;
	long			start;
	int				q;

	philo = (t_philo *)phil;
	gettimeofday(&st, NULL);
	start = st.tv_sec * 1000 + st.tv_usec / 1000;
	philo->l_eat = start;
	if (check_neat_nphilo(philo))
		return (NULL);
	while (1)
	{
		if (philo->n % 2 == 0)
			q = ft_even(philo, start);
		else if (philo->all->n_philo % 2 && philo->n == philo->all->n_philo)
			q = ft_last(philo, start);
		else
			q = ft_odd(philo, start);
		if (q)
			return (NULL);
	}
	return (NULL);
}

int	create_thread(t_all *all, t_philo **philo)
{
	int	j;

	j = 0;
	while (j < all->n_philo)
	{
		if (pthread_create(&philo[j]->id, NULL, routine, philo[j]))
		{
			free(philo);
			free(all);
			return (2);
		}
		j++;
	}
	return (0);
}

int	main(int arc, char **arv)
{
	int		j;
	t_all	*all;
	t_philo	**philo;

	if (check_args(arc, arv))
		return (2);
	all = creat_all(arv);
	philo = (t_philo **)malloc(all->n_philo * sizeof(t_philo *));
	init_philo(all, philo);
	pthread_mutex_init(&all->mutex, NULL);
	if (create_thread(all, philo))
		return (2);
	j = 0;
	while (j < all->n_philo)
	{
		if (pthread_join(philo[j]->id, NULL))
			return (free(philo), free(all), 2);
		j++;
	}
	pthread_mutex_destroy(&all->mutex);
	usleep(all->t_eat * 2000);
	j = 0;
	while (j < all->n_philo)
		free(philo[j++]);
	free(philo);
	free(all);
	return (0);
}
