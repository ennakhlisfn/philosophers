/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sennakhl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:34:18 by sennakhl          #+#    #+#             */
/*   Updated: 2024/09/16 10:36:06 by sennakhl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_p_int(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int CheckArgs(int arc, char **arv)
{
    int i;

    i = 1;
    if (arc < 5 || arc > 6)
        return (error());
    while (arv[i])
    {
        if (!is_p_int(arv[i]))
            return (error());
        i++;
    }
    return (0);
}
