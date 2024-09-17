#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_all
{
    int Nphilo;
    int Tdie;
    int Teat;
    int Tsleep;
    int Neat;
}   t_all;

t_all   *creat_all(int Nphilo, int Tdie, int Teat, int Tsleep);

int is_p_int(char *s);
int ft_atoi(char *str);
int CheckArgs(int arc, char **arv);

#endif
