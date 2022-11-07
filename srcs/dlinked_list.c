/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinked_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:23:38 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/07 13:37:24 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/dlinked_list.h>

dlist_t *dlst_new(data_t *data)
{
    dlist_t *new = malloc(sizeof(dlist_t));
    if (!new)
        return (NULL);
    new->data = data;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

void dlst_add_back(dlist_t **list, dlist_t *data)
{
    dlist_t *tmp = *list;
    if (!tmp)
    {
        *list = data;
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = data;
    data->prev = tmp;
}

void dlst_add_front(dlist_t **list, dlist_t *data)
{
    dlist_t *tmp = *list;
    if (!tmp)
    {
        *list = data;
        return;
    }
    tmp->prev = data;
    data->next = tmp;
    *list = data;
}

void dlst_add_index(dlist_t **list, dlist_t *data, size_t index)
{
    dlist_t *tmp = *list;
    if (!tmp)
    {
        *list = data;
        return;
    }
    for (size_t i = 0; i < index; ++i)
    {
        if (!tmp->next)
            break;
        tmp = tmp->next;
    }
    data->next = tmp->next;
    data->prev = tmp;
    tmp->next = data;
}

void dlst_del_one(dlist_t **list, void (*f)(data_t *))
{
    dlist_t *tmp = *list;
    if (!tmp)
        return;
    if (tmp->next)
        tmp->next->prev = NULL;
    *list = tmp->next;
    f(tmp->data);
    free(tmp);
}

void dlst_clear(dlist_t **list, void (*f)(data_t *))
{
    dlist_t *tmp = *list;
    if (!tmp)
        return;
    while (tmp)
    {
        *list = tmp->next;
        if (f)
            f(tmp->data);
        free(tmp);
        tmp = *list;
    }
}

void dlst_iter(dlist_t *list, void (*f)(data_t *))
{
    dlist_t *tmp = list;
    if (!tmp)
        return;
    while (tmp->next)
    {
        f(tmp->data);
        tmp = tmp->next;
    }
    f(tmp->data);
}

dlist_t *dlst_last(dlist_t *list)
{
    dlist_t *tmp = list;
    if (!tmp)
        return (NULL);
    while (tmp->next)
        tmp = tmp->next;
    return (tmp);
}

dlist_t *dlst_first(dlist_t *list)
{
    dlist_t *tmp = list;
    if (!tmp)
        return (NULL);
    while (tmp->prev)
        tmp = tmp->prev;
    return (tmp);
}

dlist_t *dlst_get(dlist_t *list, size_t index)
{
    dlist_t *tmp = list;
    if (!tmp)
        return (NULL);
    for (size_t i = 0; i < index; ++i)
    {
        if (!tmp->next)
            break;
        tmp = tmp->next;
    }
    return (tmp);
}

size_t dlst_size(dlist_t *list)
{
    dlist_t *tmp = list;
    size_t size = 0;
    if (!tmp)
        return (0);
    while (tmp->next)
    {
        ++size;
        tmp = tmp->next;
    }
    ++size;
    return (size);
}