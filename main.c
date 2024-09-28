/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:20:17 by sennakhl          #+#    #+#             */
/*   Updated: 2024/09/28 20:27:50 by sennakhl         ###   ########.fr       */
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
	struct	timeval	crnt;
	long	start;
	long	diff;

	philo = (t_philo *) phil;
	gettimeofday(&st, NULL);
	start = st.tv_sec * 1000 + st.tv_usec / 1000;
	if (philo->all->Neat == 0)
		return NULL;
	if (philo->all->Nphilo == 1)
	{
		printf("%ld %d died\n", philo->all->Tdie, philo->n);
		return (NULL);
	}
	gettimeofday(&crnt, NULL);
	philo->l_eat = crnt.tv_sec * 1000 + crnt.tv_usec / 1000;
	if (philo->n % 2 == 0)
		usleep(philo->all->Teat * 1000);
	if (philo->all->Nphilo % 2 && philo->n == philo->all->Nphilo)
		usleep(philo->all->Teat * 2000);
	while (1)
	{
		while (philo->left->fork || philo->right->fork)
			usleep(1);
		diff = GetDiffTime(start);
		if (philo->all->Nphilo == 0)
			return (NULL);
		if (CheckDie(philo, diff))
			return (NULL);
		gettimeofday(&crnt, NULL);
		philo->l_eat = crnt.tv_sec * 1000 + crnt.tv_usec / 1000;
		pthread_mutex_lock(&philo->all->mutex);
		philo->left->fork = 0;
		philo->left->fork = 0;
		philo->fork = 1;
		printf("%ld %d has taken a fork\n", diff, philo->n);
		printf("%ld %d has taken a fork\n", diff, philo->n);
		printf("%ld %d is eating\n", diff, philo->n);
		philo->Neat += 1;
		pthread_mutex_unlock(&philo->all->mutex);
		usleep(philo->all->Teat * 1000);
		pthread_mutex_lock(&philo->all->mutex);
		philo->left->fork = 1;
		philo->left->fork = 1;
		philo->fork = 0;
		pthread_mutex_unlock(&philo->all->mutex);
		diff = GetDiffTime(start);
		if (philo->Neat == philo->all->Neat)
			return (NULL);
		if (philo->all->Nphilo == 0)
			return (NULL);
		pthread_mutex_lock(&philo->all->mutex);
		printf("%ld %d is sleeping\n", diff, philo->n);
		pthread_mutex_unlock(&philo->all->mutex);
		usleep(philo->all->Tsleep * 1000);
		diff = GetDiffTime(start);
		if (philo->all->Nphilo == 0)
			return (NULL);
		printf("%ld %d is thinking\n", diff, philo->n);
		if (philo->all->Nphilo % 2 && philo->n % 2)
			usleep(philo->all->Teat * 1000);
		//while (philo->l_eat > philo->left->l_eat || philo->l_eat > philo->right->l_eat)
		//{
		//	if (philo->left->Neat == philo->all->Neat || philo->right->Neat == philo->all->Neat)
		//		break;
		//	usleep(1);
		//}
	}
    return NULL;
}


int main(int arc, char **arv)
{
    int 	j;
    t_all   *all;
	t_philo	**philo;

    if (CheckArgs(arc,arv))
        return (2);
    all = creat_all(arv);
	philo = (t_philo **)malloc(all->Nphilo * sizeof(t_philo *));
	pthread_mutex_init(&all->mutex, NULL);
    j = 0;
    while (j < all->Nphilo)
    {
		philo[j] = creat_philo();
		philo[j]->fork = 0;
		philo[j]->n = j + 1;
		philo[j]->all = all;
		j++;
	}
	j = 0;
    while (j < all->Nphilo)
    {
		if (j)
			philo[j]->right = philo[j - 1];
		else
			philo[j]->right = philo[all->Nphilo - 1];
		if (j < all->Nphilo - 1)
			philo[j]->left = philo[j + 1];
		else
			philo[j]->left = philo[0];
        if (pthread_create(&philo[j]->id, NULL, routine, philo[j]))
			return (2);//TODO
        j++;
    }
    j = 0;
    while (j < all->Nphilo)
    {
        if (pthread_join(philo[j]->id, NULL))
			return (j);
        j++;
    }
	pthread_mutex_destroy(&all->mutex);
	free(philo);
	free(all);
	return (0);
}    
