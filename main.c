/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 10:20:17 by sennakhl          #+#    #+#             */
/*   Updated: 2024/09/07 14:13:48 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int i;

void    *thread_fun(void *vargp)
{
    int *id = (int *)vargp;
    int k;
    i++;
    if (i == 3)
    {
        k = i;
        sleep(1);
        printf("threads   %d    %d\n", i, k);
    }
    else
        printf("threads   %d    %d\n", i, *id);
    return NULL;
}

int main()
{
    int j;
    int k;

    k = 0;
    i = 0;
    pthread_t   *thread_id;

    thread_id = (pthread_t *)malloc(5 * sizeof(pthread_t));
    j = 0;
    while (j < 5)
    {
        k = 0;
        if (j == 3)
            k = j;
        pthread_create(&thread_id[j], NULL, thread_fun, &k);
        j++;
    }
    sleep (3);
    //j = 0;
    //while (j < 5)
    //{
    //    pthread_join(thread_id[j], NULL);
    //    j++;
    //}
    free(thread_id);
}    
