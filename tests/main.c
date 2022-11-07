/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.Fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:23:50 by vvaucoul          #+#    #+#             */
/*   Updated: 2022/11/07 15:41:37 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vlib/algorithms.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

typedef struct s_data
{
    char name[32];
    int age;
} t_data;

static t_data *__create_data(char *name, int age)
{
    t_data *data = malloc(sizeof(t_data));
    if (!data)
        return (NULL);
    bzero(data, sizeof(t_data));
    bzero(data->name, 32);
    strcpy(data->name, name);
    data->age = age;
    return (data);
}

static void __print_list(data_t *data)
{
    t_data *d = (t_data *)data;

    printf("  - Name : %s, Age : %d\n", d->name, d->age);
}

static void __del_one(data_t *data)
{
    printf("Delete : %s\n", ((t_data *)data)->name);
    free(data);
}

static int __rb_compare(data_t *data1, data_t *data2)
{
    t_data *d1 = (t_data *)data1;
    t_data *d2 = (t_data *)data2;

    if (d1->age < d2->age)
        return (1);
    return (0);
}

int main(void)
{
    /*
    ** Linked List
    */
    printf("### LINKED LIST ###\n\n");
    list_t *lst = lst_new(__create_data("Vintz", 24));

    lst_add_back(&lst, lst_new(__create_data("Bob", 54)));
    lst_add_back(&lst, lst_new(__create_data("Alice", 19)));
    lst_add_back(&lst, lst_new(__create_data("John", 26)));
    lst_add_back(&lst, lst_new(__create_data("Jane", 38)));
    lst_add_back(&lst, lst_new(__create_data("Jack", 40)));
    lst_add_back(&lst, lst_new(__create_data("Jill", 23)));

    lst_iter(lst, __print_list);
    printf("Size: %lu\n", lst_size(lst));

    lst_del_one(&lst, __del_one);

    printf("First: %s\n", ((t_data *)lst_first(lst)->data)->name);
    printf("Third: %s\n", ((t_data *)lst_get(lst, 2)->data)->name);
    printf("Last: %s\n", ((t_data *)lst_last(lst)->data)->name);

    lst_add_index(&lst, lst_new(__create_data("Bill", 61)), 2);
    lst_add_front(&lst, lst_new(__create_data("Patrick", 32)));

    lst_iter(lst, __print_list);
    lst_clear(&lst, __del_one);
    lst_iter(lst, __print_list);

    printf("LINKED-LIST SUCCESS !\n");

    /*
    ** Double Linked List
    */
    printf("### DOUBLE LINKED LIST ###\n\n");
    dlist_t *dlst = dlst_new(__create_data("Vintz", 24));

    dlst_add_back(&dlst, dlst_new(__create_data("Bob", 54)));
    dlst_add_back(&dlst, dlst_new(__create_data("Alice", 19)));
    dlst_add_back(&dlst, dlst_new(__create_data("John", 26)));
    dlst_add_back(&dlst, dlst_new(__create_data("Jane", 38)));
    dlst_add_back(&dlst, dlst_new(__create_data("Jack", 40)));
    dlst_add_back(&dlst, dlst_new(__create_data("Jill", 23)));

    dlst_iter(dlst, __print_list);
    printf("Size: %lu\n", dlst_size(dlst));

    dlst_del_one(&dlst, __del_one);

    printf("First: %s\n", ((t_data *)dlst_first(dlst)->data)->name);
    printf("Third: %s\n", ((t_data *)dlst_get(dlst, 2)->data)->name);
    printf("Last: %s\n", ((t_data *)dlst_last(dlst)->data)->name);

    dlst_add_index(&dlst, dlst_new(__create_data("Bill", 61)), 2);
    dlst_add_front(&dlst, dlst_new(__create_data("Patrick", 32)));

    dlst_iter(dlst, __print_list);
    dlst_clear(&dlst, __del_one);
    dlst_iter(dlst, __print_list);

    printf("DOUBLE LINKED-LIST SUCCESS !\n");

    /*
    ** Binary Tree
    */
    printf("### BINARY TREE ###\n\n");
    btree_t *tree = btree_new(__create_data("Vintz", 24));

    btree_add_left(tree, btree_new(__create_data("Bob", 54)));
    btree_add_right(tree, btree_new(__create_data("Alice", 19)));
    btree_add_left(tree->left, btree_new(__create_data("John", 26)));
    btree_add_right(tree->left, btree_new(__create_data("Jane", 38)));
    btree_add_left(tree->right, btree_new(__create_data("Jack", 40)));
    btree_add_right(tree->right, btree_new(__create_data("Jill", 23)));

    btree_iter(tree, __print_list);
    printf("Size: %lu\n", btree_size(tree));

    btree_del_one(&tree, __del_one);

    btree_iter(tree, __print_list);
    btree_clear(&tree, __del_one);
    btree_iter(tree, __print_list);

    printf("BINARY TREE SUCCESS !\n");

    /*
    ** Red Black Tree
    */
    printf("### RED BLACK TREE ###\n\n");

    rbtree_t *rbtree = rbtree_new(__create_data("Vintz", 24));

    rbtree_insert(rbtree, rbtree_new(__create_data("Bob", 54)), __rb_compare);
    rbtree_insert(rbtree, rbtree_new(__create_data("Alice", 19)), __rb_compare);
    rbtree_insert(rbtree, rbtree_new(__create_data("John", 26)), __rb_compare);
    rbtree_insert(rbtree, rbtree_new(__create_data("Jane", 38)), __rb_compare);
    rbtree_insert(rbtree, rbtree_new(__create_data("Jack", 40)), __rb_compare);
    rbtree_insert(rbtree, rbtree_new(__create_data("Jill", 23)), __rb_compare);

    rbtree_iter(rbtree, __print_list);
    printf("Size: %lu\n", rbtree_size(rbtree));
    rbtree_clear(&rbtree, __del_one);

    printf("RED BLACK TREE SUCCESS !\n");

    printf("Size char: %lu\n", SIZEOF_CHAR());
    printf("Size short: %lu\n", SIZEOF_SHORT());
    printf("Size int: %lu\n", SIZEOF_INT());
    printf("Size float: %lu\n", SIZEOF_FLOAT());
    printf("Size long: %lu\n", SIZEOF_LONG());
    printf("Size long long: %lu\n", SIZEOF_LONG_LONG());
    printf("Size double: %lu\n", SIZEOF_DOUBLE());

    int arr[] = {5, 1, 9, 2, 4, 3, 8, 6, 7, 0};

    bubble_sort(arr, 10, SIZEOF_INT(), cmp_int);

    printf("Bubble sort: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int arr2[] = {5, 1, 9, 2, 4, 3, 8, 6, 7, 0};

    insertion_sort(arr2, 10, SIZEOF_INT(), cmp_int);

    printf("Insertion sort: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr2[i]);
    printf("\n");

    int arr3[] = {5, 1, 9, 2, 4, 3, 8, 6, 7, 0};

    selection_sort(arr3, 10, SIZEOF_INT(), cmp_int);

    printf("Selection sort: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr3[i]);
    printf("\n");

    return (0);
}