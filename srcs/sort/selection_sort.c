/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:37:53 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/07 15:40:48 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/sort.h>

static void __selection_sort_char(char *array, size_t size, int (*cmp)(void *, void *))
{
    for (size_t i = 0; i < size - 1; i++)
    {
        size_t min = i;
        for (size_t j = i + 1; j < size; j++)
        {
            if (cmp(&array[j], &array[min]) == 0)
                min = j;
        }
        if (min != i)
        {
            char tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;
        }
    }
}

static void __selection_sort_short(short *array, size_t size, int (*cmp)(void *, void *))
{
    for (size_t i = 0; i < size - 1; i++)
    {
        size_t min = i;
        for (size_t j = i + 1; j < size; j++)
        {
            if (cmp(&array[j], &array[min]) == 0)
                min = j;
        }
        if (min != i)
        {
            short tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;
        }
    }
}

static void __selection_sort_int(int *array, size_t size, int (*cmp)(void *, void *))
{
    for (size_t i = 0; i < size - 1; i++)
    {
        size_t min = i;
        for (size_t j = i + 1; j < size; j++)
        {
            if (cmp(&array[j], &array[min]) == 0)
                min = j;
        }
        if (min != i)
        {
            int tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;
        }
    }
}

static void __selection_sort_long(long *array, size_t size, int (*cmp)(void *, void *))
{
    for (size_t i = 0; i < size - 1; i++)
    {
        size_t min = i;
        for (size_t j = i + 1; j < size; j++)
        {
            if (cmp(&array[j], &array[min]) == 0)
                min = j;
        }
        if (min != i)
        {
            long tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;
        }
    }
}

void selection_sort(void *data, size_t size, short var_size, int (*cmp)(void *, void *))
{
    switch (var_size)
    {
    case 1:
        __selection_sort_char(data, size, cmp);
        break;
    case 2:
        __selection_sort_short(data, size, cmp);
        break;
    case 4:
        __selection_sort_int(data, size, cmp);
        break;
    case 8:
        __selection_sort_long(data, size, cmp);
        break;
    default:
        break;
    }
}