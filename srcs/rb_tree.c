/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:58:04 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/07 15:06:45 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithms/rb_tree.h>

rbtree_t *rbtree_new(data_t *data)
{
    rbtree_t *new = malloc(sizeof(rbtree_t));
    if (!new)
        return (NULL);
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    new->color = RED;
    return (new);
}

void rbtree_add_right(rbtree_t *tree, rbtree_t *data)
{
    if (!tree)
        return;
    tree->right = data;
}

void rbtree_add_left(rbtree_t *tree, rbtree_t *data)
{
    if (!tree)
        return;
    tree->left = data;
}

void rbtree_insert(rbtree_t *tree, rbtree_t *data, int (*f)(data_t *, data_t *))
{
    if (!tree)
        return;
    if (f(data, tree->data))
    {
        if (tree->left)
            rbtree_insert(tree->left, data, f);
        else
            rbtree_add_left(tree, data);
    }
    else
    {
        if (tree->right)
            rbtree_insert(tree->right, data, f);
        else
            rbtree_add_right(tree, data);
    }
    rbtree_fixup(tree);
}

static void rbtree_rotate_left(rbtree_t *tree)
{
    rbtree_t *tmp = tree->right;
    tree->right = tmp->left;
    tmp->left = tree;
    tree = tmp;
}

static void rbtree_rotate_right(rbtree_t *tree)
{
    rbtree_t *tmp = tree->left;
    tree->left = tmp->right;
    tmp->right = tree;
    tree = tmp;
}

void rbtree_fixup(rbtree_t *tree)
{
    if (!tree)
        return;
    if (tree->color == RED)
    {
        if (tree->left && tree->left->color == RED)
        {
            if (tree->right && tree->right->color == RED)
            {
                tree->color = RED;
                tree->left->color = BLACK;
                tree->right->color = BLACK;
            }
            else if (tree->right)
            {
                rbtree_rotate_right(tree);
                tree->color = BLACK;
                tree->right->color = RED;
            }
        }
        else if (tree->right && tree->right->color == RED)
        {
            rbtree_rotate_left(tree);
            tree->color = BLACK;
            tree->left->color = RED;
        }
    }
    rbtree_fixup(tree->left);
    rbtree_fixup(tree->right);
}

void rbtree_del_one(rbtree_t **tree, void (*f)(data_t *))
{
    if (!tree || !*tree)
        return;
    if ((*tree)->left)
        rbtree_del_one(&(*tree)->left, f);
    if ((*tree)->right)
        rbtree_del_one(&(*tree)->right, f);
    f((*tree)->data);
    free(*tree);
    *tree = NULL;
}

void rbtree_clear(rbtree_t **tree, void (*f)(data_t *))
{
    if (!tree || !*tree)
        return;
    rbtree_del_one(tree, f);
}

void rbtree_iter(rbtree_t *tree, void (*f)(data_t *))
{
    if (!tree)
        return;
    rbtree_iter(tree->left, f);
    f(tree->data);
    rbtree_iter(tree->right, f);
}

size_t rbtree_size(rbtree_t *tree)
{
    if (!tree)
        return (0);
    return (rbtree_size(tree->left) + rbtree_size(tree->right) + 1);
}
