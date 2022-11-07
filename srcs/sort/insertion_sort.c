/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:30:45 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/07 15:37:11 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/sort.h>

static void __insertion_sort_char(char *array, size_t size, int (*cmp)(void *, void *))
{
    for (size_t i = 1; i < size; i++)
    {
        char key = array[i];
        int j = (int)i - 1;
        while (j >= 0 && cmp(&array[j], &key) > 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

static void __insertion_sort_short(short *array, size_t size, int (*cmp)(void *, void *))
{
    for (size_t i = 1; i < size; i++)
    {
        short key = array[i];
        int j = (int)i - 1;
        while (j >= 0 && cmp(&array[j], &key) > 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

static void __insertion_sort_int(int *array, size_t size, int (*cmp)(void *, void *))
{
    for (size_t i = 1; i < size; i++)
    {
        int key = array[i];
        int j = (int)i - 1;
        while (j >= 0 && cmp(&array[j], &key) > 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

static void __insertion_sort_long(long *array, size_t size, int (*cmp)(void *, void *))
{
    for (size_t i = 1; i < size; i++)
    {
        long key = array[i];
        int j = (int)i - 1;
        while (j >= 0 && cmp(&array[j], &key) > 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void insertion_sort(void *data, size_t size, short var_size, int (*cmp)(void *, void *))
{
    switch (var_size)
    {
    case 1:
        __insertion_sort_char(data, size, cmp);
        break;
    case 2:
        __insertion_sort_short(data, size, cmp);
        break;
    case 4:
        __insertion_sort_int(data, size, cmp);
        break;
    case 8:
        __insertion_sort_long(data, size, cmp);
        break;
    default:
        break;
    }
}