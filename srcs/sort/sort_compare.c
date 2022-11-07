/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_compare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:11:13 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/07 15:29:33 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/sort.h>
#include <string.h>

int cmp_short(void *a, void *b)
{
    return (*(short *)a > *(short *)b);
}

int cmp_int(void *a, void *b)
{
    return (*(int *)a > *(int *)b);
}

int cmp_char(void *a, void *b)
{
    return (*(char *)a > *(char *)b);
}

int cmp_string(void *a, void *b)
{
    return (strcmp((char *)a, (char *)b) > 0);
}

int cmp_string_reverse(void *a, void *b)
{
    return (strcmp((char *)a, (char *)b) < 0);
}

int cmp_float(void *a, void *b)
{
    return (*(float *)a > *(float *)b);
}

int cmp_double(void *a, void *b)
{
    return (*(double *)a > *(double *)b);
}

int cmp_long(void *a, void *b)
{
    return (*(long *)a > *(long *)b);
}

