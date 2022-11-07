/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:38:34 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/07 13:53:52 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/binary_tree.h>

btree_t *btree_new(data_t *data)
{
    btree_t *new = malloc(sizeof(btree_t));
    if (!new)
        return (NULL);
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return (new);
}

void btree_add_right(btree_t *tree, btree_t *data)
{
    if (!tree)
        return;
    tree->right = data;
}

void btree_add_left(btree_t *tree, btree_t *data)
{
    if (!tree)
        return;
    tree->left = data;
}

void btree_del_one(btree_t **tree, void (*f)(data_t *))
{
    if (!tree || !*tree)
        return;
    if ((*tree)->left)
        btree_del_one(&(*tree)->left, f);
    if ((*tree)->right)
        btree_del_one(&(*tree)->right, f);
    if (f)
        f((*tree)->data);
    free(*tree);
    *tree = NULL;
}

void btree_clear(btree_t **tree, void (*f)(data_t *))
{
    if (!tree || !*tree)
        return;
    btree_del_one(tree, f);
    *tree = NULL;
}

void btree_iter(btree_t *tree, void (*f)(data_t *))
{
    if (!tree)
        return;
    f(tree->data);
    if (tree->left)
        btree_iter(tree->left, f);
    if (tree->right)
        btree_iter(tree->right, f);
}

size_t btree_size(btree_t *tree)
{
    size_t size = 0;
    if (!tree)
        return (0);
    size += btree_size(tree->left);
    size += btree_size(tree->right);
    return (size + 1);
}
