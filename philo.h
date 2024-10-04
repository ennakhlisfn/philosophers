/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:18:05 by sennakhl          #+#    #+#             */
/*   Updated: 2024/10/04 15:51:49 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_all
{
	pthread_t		*ids;
	pthread_mutex_t	mutex;
	long			t_die;
	long			t_eat;
	long			t_sleep;
	long			n_philo;
	long			n_eat;
	long			forks;
	int				die;
}					t_all;

typedef struct s_philo
{
	pthread_t		id;
	t_all			*all;
	int				n;
	long			l_eat;
	int				n_eat;
}					t_philo;

t_philo				*creat_philo(void);
t_all				*creat_all(char **arv);

void				ft_eating(t_philo *philo, long start);
void				init_philo(t_all *all, t_philo **philo);

long				get_diff_time(long start);
long				get_diff_time(long start);
long				ft_atoi(char *str);

int					check_neat_nphilo(t_philo *philo);
int					main_routine(t_philo *philo, long start);
int					ft_last(t_philo *philo, long start);
int					ft_even(t_philo *philo, long start);
int					ft_odd(t_philo *philo, long start);
int					check_die(t_philo *philo, long diff);
int					error(void);
int					is_p_int(char *s);
int					check_args(int arc, char **arv);

#endif
