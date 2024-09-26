/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:20:17 by sennakhl          #+#    #+#             */
/*   Updated: 2024/09/26 11:53:23 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long GetDiffTime(long start)
{
	struct	timeval	curnt;
	long	diff;

	gettimeofday(&curnt, NULL);
	diff = curnt.tv_sec * 1000 + curnt.tv_usec / 1000;
	diff -= start;
	return (diff);
}

void    *routine(void *phil)
{
	t_philo *philo;
	struct	timeval	st;
	long	start;
	long	diff;

	philo = (t_philo *) phil;
	philo->rank = philo->n;
	gettimeofday(&st, NULL);
	start = st.tv_sec * 1000 + st.tv_usec / 1000;
	while (1)
	{
		if (philo->n % 2 == 0)
		{
			pthread_mutex_lock(&philo->all->mutex);
			diff = GetDiffTime(start);
			printf("%ld %d has taken a fork\n", diff, philo->rank);
			printf("%ld %d has taken a fork\n", diff, philo->rank);
			printf("%ld %d is eating\n", diff, philo->rank);
			philo->Neat += 1;
			pthread_mutex_unlock(&philo->all->mutex);
			usleep(philo->all->Teat * 1000);
			if (philo->Neat == philo->all->Neat)
				break;
			diff = GetDiffTime(start);
			printf("%ld %d is sleeping\n", diff, philo->rank);
			usleep(philo->all->Tsleep * 1000);
			diff = GetDiffTime(start);
			printf("%ld %d is thinking\n", diff, philo->rank);
		}
		philo->n = philo->next->n;
		if (philo->all->Nphilo % 2 == 0 && philo->n != philo->all->Nphilo)
			usleep(philo->all->Teat * 1000);
		usleep(philo->all->Teat * 1000);
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
