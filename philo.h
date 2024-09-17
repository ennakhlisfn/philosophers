#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_philo
{
	pthread_t		id;
	int				n;
	unsigned int	l_eat;
	struct s_philo	*next;
}	t_philo;

typedef struct s_all
{
	t_philo	*philo;
    pthread_t   *ids;
	pthread_mutex_t	mutex;
    int Nphilo;
    int Tdie;
    int Teat;
    int Tsleep;
    int Neat;
}   t_all;

t_philo	*creat_philo();
t_all   *creat_all(char **arv);

int error();
int is_p_int(char *s);
int ft_atoi(char *str);
int CheckArgs(int arc, char **arv);

#endif
