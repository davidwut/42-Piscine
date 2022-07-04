/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:13:27 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/24 10:50:41 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
							int (*cmpf)(void *, void *))
{
	void	*res;

	if (root == NULL)
		return (NULL);
	res = NULL;
	if (root->left)
		res = btree_search_item(root->left, data_ref, cmpf);
	if (!res && (*cmpf)(data_ref, root->item) == 0)
		res = root->item;
	if (!res && root->right)
		res = btree_search_item(root->right, data_ref, cmpf);
	return (res);
}
