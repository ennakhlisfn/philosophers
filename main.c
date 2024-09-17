/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:20:17 by sennakhl          #+#    #+#             */
/*   Updated: 2024/09/17 12:06:10 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *thread_fun(void *phil)
{
	t_philo *philo;

	philo = (t_philo *) phil;
	if (philo->n % 2)
	sleep(3);
    printf("%d statr eating\n", philo->n);
	sleep(3);
    printf("%d statr sleeping\n", philo->n);
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
		philo->n = j;
        if (pthread_create(&philo->id, NULL, thread_fun, philo))
			return (j);
        j++;
		if (j < all->Nphilo)
			philo->next = creat_philo();
		philo = philo->next;
    }
	philo = head;
    j = 0;
    while (j < all->Nphilo)
    {
        if (pthread_join(philo->id, NULL))
			return (j);
		philo = philo->next;
        j++;
    }
	pthread_mutex_destroy(&all->mutex);
	return (0);
}    
