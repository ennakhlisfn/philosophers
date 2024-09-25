#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_all
{
    pthread_t   *ids;
	pthread_mutex_t	mutex;
    int Nphilo;
    int Tdie;
    int Teat;
    int Tsleep;
    int Neat;
}   t_all;

typedef struct s_philo
{
	pthread_t		id;
	t_all			*all;
	int				n;
	unsigned int	l_eat;
	struct s_philo	*next;
    int Neat;
}	t_philo;

t_philo	*creat_philo();
t_all   *creat_all(char **arv);

void	ft_free(t_philo	*philo);

int error();
int is_p_int(char *s);
int ft_atoi(char *str);
int CheckArgs(int arc, char **arv);

#endif
