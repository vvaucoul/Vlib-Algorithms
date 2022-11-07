/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlinked_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:23:49 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/07 13:33:44 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLINKED_LIST_H
# define DLINKED_LIST_H

#include <stdlib.h>

typedef void data_t;

typedef struct s_dlist
{
    data_t *data;
    struct s_dlist *next;
    struct s_dlist *prev;
} t_dlist;

typedef t_dlist dlist_t;

/**
 * @brief Create a new dlist_t element
 * 
 * @param data 
 * @return dlist_t* 
 */
extern dlist_t *dlst_new(data_t *data);

/**
 * @brief Add a new element at the end of the list
 * 
 * @param list 
 * @param data 
 */
extern void dlst_add_back(dlist_t **list, dlist_t *data);

/**
 * @brief Add a new element at the beginning of the list
 * 
 * @param list 
 * @param data 
 */
extern void dlst_add_front(dlist_t **list, dlist_t *data);

/**
 * @brief Add a new element at the given index
 * 
 * @param list 
 * @param data 
 * @param index 
 */
extern void dlst_add_index(dlist_t **list, dlist_t *data, size_t index);

/**
 * @brief Remove an element from the list with the given function
 * 
 * @param list 
 * @param index 
 * @param f 
 */
extern void dlst_del_one(dlist_t **list, void (*f)(data_t *));

/**
 * @brief Remove all elements from the list with the given function
 *
 * @param list
 * @param f
 */
extern void dlst_clear(dlist_t **list, void (*f)(data_t *));

/**
 * @brief Iterate over the list with the given function
 * 
 * @param list 
 * @param f 
 */
extern void dlst_iter(dlist_t *list, void (*f)(data_t *));

/**
 * @brief Get the last element of the list
 * 
 * @param list 
 * @return dlist_t* 
 */
extern dlist_t *dlst_last(dlist_t *list);

/**
 * @brief Get the first element of the list
 * 
 * @param list 
 * @return dlist_t* 
 */
extern dlist_t *dlst_first(dlist_t *list);

/**
 * @brief Get the element at the given index
 * 
 * @param list 
 * @param index 
 * @return dlist_t* 
 */
extern dlist_t *dlst_get(dlist_t *list, size_t index);

/**
 * @brief Get the size of the list
 * 
 * @param list 
 * @return size_t 
 */
extern size_t dlst_size(dlist_t *list);

#endif /* !DLINKED_LIST_H */