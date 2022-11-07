/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:43:22 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/07 15:42:26 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

extern void bubble_sort(void *data, size_t size, short var_size, int (*cmp)(void *, void *));
extern void insertion_sort(void *data, size_t size, short var_size, int (*cmp)(void *, void *));
extern void selection_sort(void *data, size_t size, short var_size, int (*cmp)(void *, void *));

/*******************************************************************************
 *                              COMPARE FUNCTIONS                              *
 ******************************************************************************/

extern int cmp_short(void *a, void *b);
extern int cmp_int(void *a, void *b);
extern int cmp_char(void *a, void *b);
extern int cmp_string(void *a, void *b);
extern int cmp_string_reverse(void *a, void *b);
extern int cmp_float(void *a, void *b);
extern int cmp_double(void *a, void *b);
extern int cmp_long(void *a, void *b);

#endif /* SORT_H */