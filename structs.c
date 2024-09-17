/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:46:43 by sennakhl          #+#    #+#             */
/*   Updated: 2024/09/17 11:07:41 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*creat_philo()
{
	t_philo *philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = 0;
	philo->n = 0;
	philo->l_eat = 0;
	philo->next = NULL;
	return (philo);
}
	

t_all   *creat_all(char **arv)
{

    t_all   *all;

    all = (t_all *)malloc(sizeof(t_all));
    if (!all)
        return (NULL);
    all->Nphilo = ft_atoi(arv[1]);
    all->Tdie = ft_atoi(arv[2]);
    all->Teat = ft_atoi(arv[3]);
    all->Tsleep = ft_atoi(arv[4]);
    all->Neat = ft_atoi(arv[5]);
    return (all);
}
