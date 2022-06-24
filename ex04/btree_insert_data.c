/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:37:19 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/24 10:10:48 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree	*node;

	if (*root == NULL)
		*root = btree_create_node(item);
	else
	{
		node = *root;
		if ((*cmpf)(item, node->item) < 0)
		{
			if (node->left)
				btree_insert_data(&node->left, item, cmpf);
			else
				node->left = btree_create_node(item);
		}
		else
		{
			if (node->right)
				btree_insert_data(&node->right, item, cmpf);
			else
				node->right = btree_create_node(item);
		}
	}
}
