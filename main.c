/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:20:17 by sennakhl          #+#    #+#             */
/*   Updated: 2024/09/25 13:14:44 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *routine(void *phil)
{
	t_philo *philo;
	struct	timeval	start;
	struct	timeval	curnt;

	gettimeofday(&start, NULL);
	philo = (t_philo *) phil;
	if (philo->n % 2 == 0)
		usleep(philo->all->Teat);
	gettimeofday(&curnt, NULL);
	while (1)
	{
		pthread_mutex_lock(&philo->all->mutex);
		printf("%ld %d has taken a fork\n", curnt.tv_usec - start.tv_usec, philo->n);
		printf("%ld %d has taken a fork\n", curnt.tv_usec - start.tv_usec, philo->n);
		printf("%ld %d is eating\n", curnt.tv_usec - start.tv_usec, philo->n);
		pthread_mutex_unlock(&philo->all->mutex);
		philo->Neat += 1;
		if (philo->Neat == philo->all->Neat)
			break;
		usleep(philo->all->Teat);
		gettimeofday(&curnt, NULL);
		printf("%ld %d is sleeping\n", curnt.tv_usec - start.tv_usec, philo->n);
		usleep(philo->all->Tsleep);
		gettimeofday(&curnt, NULL);
		printf("%ld %d is thinking\n", curnt.tv_usec - start.tv_usec, philo->n);
	}
    return NULL;
}


int main(int arc, char **arv)
{
    int 	j;
    t_all   *all;
	t_philo	*philo;
	t_philo *head;

    if (CheckArgs(arc,arv))
        return (2);
    all = creat_all(arv);
	philo = creat_philo();
	head = philo;
	pthread_mutex_init(&all->mutex, NULL);
    j = 0;
    while (j < all->Nphilo)
    {
		philo->n = j + 1;
		philo->all = all;
        if (pthread_create(&philo->id, NULL, routine, philo))
			return (j);//TODO
        j++;
		if (j == all->Nphilo)
			break ;
		philo->next = creat_philo();
		philo = philo->next;
    }
	philo->next = head;
	philo = philo->next;
    j = 0;
    while (j < all->Nphilo)
    {
        if (pthread_join(philo->id, NULL))
			return (j);
		philo = philo->next;
        j++;
    }
	pthread_mutex_destroy(&all->mutex);
	ft_free(philo);
	return (0);
}    
