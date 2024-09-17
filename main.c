/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:20:17 by sennakhl          #+#    #+#             */
/*   Updated: 2024/09/16 12:51:44 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//void    *thread_fun(void *vargp)
//{
//    int *k = (int*)vargp;
//    printf("fffthreads   %d    %d\n", i, *k);
//    return NULL;
//}

int error()
{
    write(2, "WRONG ARGUMENTS\n", 16);
    return (2);
}

int main(int arc, char *arv[])
{
//    int j;
//    int n;
    t_all   all;

    all = creat_all(ft_atoi(arv);
    if (CheckArgs(arc,arv))
        return (2);
    
    printf("%d\n", ft_atoi(arv[1]));
//    n = ft_atoi(arv[1]);
//    i = 0;
//    pthread_t   *thread_id;
//
//    thread_id = (pthread_t *)malloc(n * sizeof(pthread_t));
//    if (!thread_id)
//        return 24;
//    j = 0;
//    while (j < n)
//    {
//        pthread_create(&thread_id[j], NULL, thread_fun, &j);
//        j++;
//    }
//    j = 0;
//    while (j < n)
//    {
//        pthread_join(thread_id[j], NULL);
//        j++;
//    }
//    free(thread_id);
}    
