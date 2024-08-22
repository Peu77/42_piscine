/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:30:06 by eebert            #+#    #+#             */
/*   Updated: 2024/08/20 18:44:58 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

typedef struct s_queue_node
{
	t_btree				*node;
	int					level;
	struct s_queue_node	*next;
}						t_queue_node;

typedef struct s_queue
{
	t_queue_node		*front;
	t_queue_node		*rear;
}						t_queue;

static void	queue_push(t_queue *q, t_btree *node, int level)
{
	t_queue_node	*new_node;

	new_node = malloc(sizeof(t_queue_node));
	if (!new_node)
		return ;
	new_node->node = node;
	new_node->level = level;
	new_node->next = NULL;
	if (q->rear == NULL)
	{
		q->front = new_node;
		q->rear = new_node;
		return ;
	}
	q->rear->next = new_node;
	q->rear = new_node;
}

static t_queue_node	*queue_pop(t_queue *q)
{
	t_queue_node	*temp;

	if (q->front == NULL)
		return (NULL);
	temp = q->front;
	q->front = q->front->next;
	if (q->front == NULL)
		q->rear = NULL;
	return (temp);
}

static int	is_queue_empty(t_queue *q)
{
	return (q->front == NULL);
}

void	process_queue(t_queue *q, void (*applyf)(void *item, int current_level,
			int is_first_elem))
{
	int				current_level;
	int				last_level;
	t_queue_node	*node;

	current_level = 0;
	last_level = -1;
	while (!is_queue_empty(q))
	{
		node = queue_pop(q);
		if (node->level != last_level)
		{
			current_level = node->level;
			last_level = node->level;
			applyf(node->node->item, current_level, 1);
		}
		else
		{
			applyf(node->node->item, current_level, 0);
		}
		if (node->node->left)
			queue_push(q, node->node->left, node->level + 1);
		if (node->node->right)
			queue_push(q, node->node->right, node->level + 1);
		free(node);
	}
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first_elem))
{
	t_queue	q;

	if (!root)
		return ;
	q.front = NULL;
	q.rear = NULL;
	queue_push(&q, root, 0);
	process_queue(&q, applyf);
}

// #include <stdio.h>

// void	test_applyf(void *item, int current_level, int is_first_elem)
// {
// 	printf("Item: %d, Level: %d, First: %d\n", *(int *)item, current_level,
// 		is_first_elem);
// }

// t_btree	*new_node(int value)
// {
// 	t_btree	*node;
// 	int		*item;

// 	node = malloc(sizeof(t_btree));
// 	item = malloc(sizeof(int));
// 	*item = value;
// 	node->item = item;
// 	node->left = node->right = NULL;
// 	return (node);
// }

// void	test_single_node(void)
// {
// 	t_btree	*root;

// 	root = new_node(1);
// 	btree_apply_by_level(root, test_applyf);
// 	free(root->item);
// 	free(root);
// }

// void	test_multiple_levels(void)
// {
// 	t_btree	*root;

// 	root = new_node(1);
// 	root->left = new_node(2);
// 	root->right = new_node(3);
// 	root->left->left = new_node(4);
// 	root->left->right = new_node(5);
// 	btree_apply_by_level(root, test_applyf);
// 	free(root->left->left->item);
// 	free(root->left->right->item);
// 	free(root->left->item);
// 	free(root->right->item);
// 	free(root->item);
// 	free(root->left->left);
// 	free(root->left->right);
// 	free(root->left);
// 	free(root->right);
// 	free(root);
// }

// void	test_empty_tree(void)
// {
// 	btree_apply_by_level(NULL, test_applyf);
// }

// int	main(void)
// {
// 	test_single_node();
// 	test_multiple_levels();
// 	test_empty_tree();
// 	return (0);
// }