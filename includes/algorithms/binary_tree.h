/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:38:50 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/07 13:55:06 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>

typedef void data_t;

typedef struct s_btree
{
    data_t *data;
    struct s_btree *left;
    struct s_btree *right;
} t_btree;

typedef t_btree btree_t;

/**
 * @brief Create a new binary tree node
 * 
 * @param data 
 * @return btree_t* 
 */
extern btree_t *btree_new(data_t *data);

/**
 * @brief Add a node to the right of the tree
 * 
 * @param tree 
 * @param data 
 */
extern void btree_add_right(btree_t *tree, btree_t *data);

/**
 * @brief Add a node to the left of the tree
 * 
 * @param tree 
 * @param data 
 */
extern void btree_add_left(btree_t *tree, btree_t *data);

/**
 * @brief Delete a node from the tree
 * 
 * @param tree 
 * @return btree_t* 
 */
extern void btree_del_one(btree_t **tree, void (*f)(data_t *));

/**
 * @brief Clear the tree
 * 
 * @param tree 
 */
extern void btree_clear(btree_t **tree, void (*f)(data_t *));

/**
 * @brief Apply a function to each node of the tree
 * 
 * @param tree 
 * @param f 
 */
extern void btree_iter(btree_t *tree, void (*f)(data_t *));

/**
 * @brief Get the size of the tree
 * 
 * @param tree 
 * @return size_t 
 */
extern size_t btree_size(btree_t *tree);

#endif /* !BINARY_TREE_H */