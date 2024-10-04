/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:46:43 by sennakhl          #+#    #+#             */
/*   Updated: 2024/10/04 14:36:48 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*creat_philo(void)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = 0;
	philo->n = 0;
	philo->n_eat = 0;
	philo->l_eat = 0;
	return (philo);
}

t_all	*creat_all(char **arv)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		return (NULL);
	all->n_philo = ft_atoi(arv[1]);
	all->t_die = ft_atoi(arv[2]);
	all->t_eat = ft_atoi(arv[3]);
	all->t_sleep = ft_atoi(arv[4]);
	all->forks = 0;
	if (arv[5])
		all->n_eat = ft_atoi(arv[5]);
	else
		all->n_eat = -1;
	return (all);
}

void	init_philo(t_all *all, t_philo **philo)
{
	int	j;

	j = 0;
	while (j < all->n_philo)
	{
		philo[j] = creat_philo();
		philo[j]->n = j + 1;
		philo[j]->all = all;
		j++;
	}
	all->die = 1;
}
