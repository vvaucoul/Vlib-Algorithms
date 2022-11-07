/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:42:55 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/07 15:27:54 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/sort.h>

static void __bubble_sort_char(char *array, size_t size, int (*cmp)(void *, void *))
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size - 1; ++j)
        {
            if (cmp(&array[j], &array[j + 1]) > 0)
            {
                char tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

static void __bubble_sort_short(short *array, size_t size, int (*cmp)(void *, void *))
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size - 1; ++j)
        {
            if (cmp(&array[j], &array[j + 1]) > 0)
            {
                short tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

static void __bubble_sort_int(int *array, size_t size, int (*cmp)(void *, void *))
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size - 1; ++j)
        {
            if (cmp(&array[j], &array[j + 1]) > 0)
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

static void __bubble_sort_long(long *array, size_t size, int (*cmp)(void *, void *))
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size - 1; ++j)
        {
            if (cmp(&array[j], &array[j + 1]) > 0)
            {
                long tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void bubble_sort(void *data, size_t size, short var_size, int (*cmp)(void *, void *))
{
    switch (var_size)
    {
    case 1:
        __bubble_sort_char(data, size, cmp);
        break;
    case 2:
        __bubble_sort_short(data, size, cmp);
        break;
    case 4:
        __bubble_sort_int(data, size, cmp);
        break;
    case 8:
        __bubble_sort_long(data, size, cmp);
        break;
    default:
        break;
    }
}