/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:20:47 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/07 12:41:01 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/linked_list.h>

list_t *lst_new(data_t *data)
{
    list_t *new;

    if (!(new = malloc(sizeof(list_t))))
        return (NULL);
    new->data = data;
    new->next = NULL;
    return (new);
}

void lst_add_back(list_t **list, list_t *new)
{
    list_t *tmp = *list;

    if (!(*list) || !new)
        return;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

void lst_add_front(list_t **list, list_t *new)
{
    if (!(*list) || !new)
        return;
    new->next = *list;
    *list = new;
}

void lst_add_index(list_t **list, list_t *new, size_t index)
{
    list_t *tmp = *list;
    size_t i = 0;

    if (!(*list) || !new)
        return;
    while (tmp->next && i < index)
    {
        tmp = tmp->next;
        ++i;
    }
    new->next = tmp->next;
    tmp->next = new;
}

void lst_del_one(list_t **list, void (*f)(data_t *))
{
    list_t *tmp = *list;

    if (!(*list))
        return;
    *list = (*list)->next;
    if (f)
        f(tmp->data);
    free(tmp);
}

void lst_clear(t_list **list, void (*f)(data_t *))
{
    list_t *tmp = *list;

    if (!(*list))
        return;
    while (tmp)
    {
        *list = (*list)->next;
        if (f)
            f(tmp->data);
        free(tmp);
        tmp = *list;
    }
}

void lst_iter(list_t *list, void (*f)(data_t *))
{
    list_t *tmp = list;

    if (!list)
        return;
    while (tmp)
    {
        f(tmp->data);
        tmp = tmp->next;
    }
}

list_t *lst_last(list_t *list)
{
    list_t *tmp = list;

    if (!list)
        return (NULL);
    while (tmp->next)
        tmp = tmp->next;
    return (tmp);
}

list_t *lst_first(list_t *list)
{
    if (!list)
        return (NULL);
    return (list);
}

list_t *lst_get(list_t *list, size_t index)
{
    list_t *tmp = list;
    size_t i = 0;

    if (!list)
        return (NULL);
    while (tmp->next && i < index)
    {
        tmp = tmp->next;
        ++i;
    }
    return (tmp);
}

size_t lst_size(list_t *list)
{
    list_t *tmp = list;
    size_t i = 0;

    if (!list)
        return (0);
    while (tmp)
    {
        tmp = tmp->next;
        ++i;
    }
    return (i);
}