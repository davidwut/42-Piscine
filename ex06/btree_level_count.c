/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:37:40 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/24 11:59:50 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	highest;
	int	current;

	highest = 0;
	current = 0;
	if (root->left)
		current = 1 + btree_level_count(root->left);
	if (current > highest)
		highest = current;
	current = 0;
	if (root->right)
		current = 1 + btree_level_count(root->right);
	if (current > highest)
		highest = current;
	return (highest);
}
