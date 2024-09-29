/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:34:18 by sennakhl          #+#    #+#             */
/*   Updated: 2024/09/29 18:52:56 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	CheckDie(t_philo *philo, long diff)
{
	if (GetDiffTime(philo->l_eat) > philo->all->Tdie)
	{
		if (philo->all->Nphilo && philo->all->die)
		{
			philo->all->die = 0;
			philo->all->Nphilo = 0;
			pthread_mutex_lock(&philo->all->mutex);
			usleep(1000);
			philo->left->fork = 1;
			philo->left->fork = 1;
			philo->fork = 0;
			printf("%ld %d died\n", diff, philo->n);
			pthread_mutex_unlock(&philo->all->mutex);
		}
		else
			return (0);
		return (1);
	}
	return (0);
}

int is_p_int(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int CheckArgs(int arc, char **arv)
{
    int i;

    i = 1;
    if (arc < 5 || arc > 6)
        return (error());
    while (arv[i])
    {
        if (!is_p_int(arv[i]))
            return (error());
        i++;
    }
    return (0);
}
