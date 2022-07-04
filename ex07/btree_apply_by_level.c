/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:05:59 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/24 13:37:51 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

typedef struct s_data {
	t_btree	*node;
	int		level;
}	t_data;

int	data_len(t_data **data)
{
	int	count;

	count = -1;
	while (data[++count])
		;
	return (count);
}

t_data	**add_data(t_btree *node, int level, t_data **data)
{
	t_data	**res;
	int		i;

	res = malloc(sizeof(*res) * (data_len(data) + 2));
	i = -1;
	while (++i < data_len(data))
		res[i] = data[i];
	res[i + 1] = data[i];
	res[i] = malloc(sizeof(*res[i]));
	res[i]->level = level;
	res[i]->node = node;
	return (res);
}

void	_helper(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem),
		int level, t_data ***data)
{
	if (root)
	{
		*data = add_data(root, level, *data);
		if (root->left)
			_helper(root->left, applyf, level + 1, data);
		if (root->right)
			_helper(root->right, applyf, level + 1, data);
	}
}

void	_apply(t_data **data,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		i;
	int		is_first;
	int		current_level;
	int		done;
	int		temp_level;

	current_level = 0;
	done = 0;
	while (!done)
	{
		done = 1;
		i = -1;
		is_first = 1;
		while (++i < data_len(data))
		{
			temp_level = data[i]->level;
			if (temp_level == current_level)
			{
				(*applyf)(data[i]->node->item, current_level, is_first);
				is_first = 0;
			}
		}
		current_level++;
		done = is_first;
	}
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_data	**data;

	data = malloc(sizeof(*data));
	data[0] = 0;
	if (!root)
		return ;
	_helper(root, applyf, 0, &data);
	_apply(data, applyf);
}
