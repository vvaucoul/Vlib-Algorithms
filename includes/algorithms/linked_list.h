/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:19:54 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/07 13:24:33 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef void data_t;

typedef struct s_list
{
    data_t *data;
    struct s_list *next;
} t_list;

typedef t_list list_t;

/**
 * @brief Create a new list element
 * 
 * @param data 
 * @return list_t* 
 */
extern list_t *lst_new(data_t *data);

/**
 * @brief Add a new element to the list at the end
 * 
 * @param list 
 * @param new 
 */
extern void lst_add_back(list_t **list, list_t *new);

/**
 * @brief Add a new element to the list at the start
 * 
 * @param list 
 * @param new 
 */
extern void lst_add_front(list_t **list, list_t *new);

/**
 * @brief Add a new element to the list at the given index
 * 
 * @param list 
 * @param new 
 * @param index 
 */
extern void lst_add_index(list_t **list, list_t *new, size_t index);

/**
 * @brief Remove an element from the list with the given function
 * 
 * @param list 
 * @param f 
 */
extern void lst_del_one(list_t **list, void (*f)(data_t *));

/**
 * @brief Remove all elements from the list with the given function
 * 
 * @param list 
 * @param f 
 */
extern void lst_clear(list_t **list, void (*f)(data_t *));

/**
 * @brief Iterate a function on each element of the list
 * 
 * @param list 
 * @param f 
 */
extern void lst_iter(list_t *list, void (*f)(data_t *));

/**
 * @brief Get the last element of the list
 * 
 * @param list 
 * @return list_t* 
 */
extern list_t *lst_last(list_t *list);

/**
 * @brief Get the first element of the list
 * 
 * @param list 
 * @return list_t* 
 */
extern list_t *lst_first(list_t *list);

/**
 * @brief Get the element at the given index
 * 
 * @param list 
 * @param index 
 * @return list_t* 
 */
extern list_t *lst_get(list_t *list, size_t index);

/**
 * @brief Get the size of the list
 * 
 * @param list 
 * @return size_t 
 */
extern size_t lst_size(list_t *list);

#endif /* !LINKED_LIST_H */