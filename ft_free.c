/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:25:57 by sennakhl          #+#    #+#             */
/*   Updated: 2024/09/25 11:09:07 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_philo	*philo)
{
	t_philo	*prev;
	int		n;

	n = philo->all->Nphilo;
	free(philo->all);
	while (n)
	{
		prev = philo;
		philo = philo->next;
		free(prev);
		n--;
	}
}
