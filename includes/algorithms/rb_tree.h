/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:54:30 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/07 15:43:43 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_H
#define RB_TREE_H

#include <stdlib.h>

typedef void data_t;

enum e_rb_color
{
    RED,
    BLACK
};

typedef enum e_rb_color rb_color_t;

typedef struct s_rbtree
{
    data_t *data;
    struct s_rbtree *left;
    struct s_rbtree *right;
    struct s_rbtree *parent;
    rb_color_t color;
} t_rbtree;

typedef t_rbtree rbtree_t;

/**
 * @brief Create a new rbtree element
 * 
 * @param data 
 * @return rbtree_t* 
 */
extern rbtree_t *rbtree_new(data_t *data);

/**
 * @brief Add a new element to the rbtree at right
 * 
 * @param tree 
 * @param data 
 */
extern void rbtree_add_right(rbtree_t *tree, rbtree_t *data);

/**
 * @brief Add a new element to the rbtree at left
 * 
 * @param tree 
 * @param data 
 */
extern void rbtree_add_left(rbtree_t *tree, rbtree_t *data);

/**
 * @brief Insert a new element to the rbtree
 * 
 * @param tree 
 * @param data 
 * @param f 
 */
extern void rbtree_insert(rbtree_t *tree, rbtree_t *data, int (*f)(data_t *, data_t *));

/**
 * @brief Fix the rbtree after an insertion
 * 
 * @param tree 
 */
extern void rbtree_fixup(rbtree_t *tree);

/**
 * @brief Delete a rbtree element
 * 
 * @param tree 
 * @param f 
 */
extern void rbtree_del_one(rbtree_t **tree, void (*f)(data_t *));

/**
 * @brief Delete a rbtree
 * 
 * @param tree 
 * @param f 
 */
extern void rbtree_clear(rbtree_t **tree, void (*f)(data_t *));

/**
 * @brief Iterate through a rbtree
 * 
 * @param tree 
 * @param f 
 */
extern void rbtree_iter(rbtree_t *tree, void (*f)(data_t *));

/**
 * @brief Get the rbtree size
 * 
 * @param tree 
 * @return size_t 
 */
extern size_t rbtree_size(rbtree_t *tree);

#endif /* !RB_TREE_H */