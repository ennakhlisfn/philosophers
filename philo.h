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
    long Tdie;
    long Teat;
    long Tsleep;
    int Neat;
}   t_all;

typedef struct s_philo
{
	pthread_t		id;
	t_all			*all;
	int				n;
	long	l_eat;
	int		fork;
	struct s_philo	*left;
	struct s_philo	*right;
    int Neat;
}	t_philo;

t_philo	*creat_philo();
t_all   *creat_all(char **arv);

void	ft_free(t_philo	*philo);

long GetDiffTime(long start);

int	CheckDie(t_philo *philo, long diff);
int error();
int is_p_int(char *s);
int ft_atoi(char *str);
int CheckArgs(int arc, char **arv);

#endif
