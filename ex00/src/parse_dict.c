/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:27:51 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/25 16:53:44 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#include "linked_list.c"
#include "parse_dict_help.c"
#include "ft_putstr.c"

#define UINT_MAX 4294967295

enum e_line {
	INVALID,
	VALID,
	EMPTY
};

char	*ft_strslice(char *str, int from, int to)
{
	char	*res;
	int		i;

	res = malloc(sizeof(*res) * (to - from + 1));
	i = -1;
	while (++i < to - from)
		res[i] = str[from + i];
	res[i] = 0;
	return (res);
}

void	insert_node(t_list **begin, char *str, int len)
{
		t_ll	value;
		char			*text;
		int				i;

		i = 0;
		value = not_atoi(str, &i);
		if (value > UINT_MAX || value < 0)
			return ;
		while (str[i] == ' ')
			i++;
		i++;
		while (str[i] == ' ')
			i++;
		text = ft_strslice(str, i, len);
		ft_list_push_back(begin, value, text);
}

int	valid_line(char *str, int len)
{
	int	i;

	i = 0;
	if (len < 3)
		return (EMPTY);
	str = advance(str, " ");
	if (*str == '+' || *str == '-')
		str++;
	str = advance_range(str, '0', '9');
	str = advance(str, " ");
	if (*str != ':')
		return (INVALID);
	str++;
	str = advance(str, " ");
	if (!(' ' < *str && *str <= '~'))
		return (INVALID);
	return (VALID);
}

t_list	*build_dict(char *buffer, int size)
{
	t_list *head;

	int		i;
	int		j;
	int		err;

	head = NULL;
	i = 0;
	while (buffer[i] && i < size)
	{
		j = 0;
		while (buffer[i + j] && buffer[i + j] != '\n')
			j++;
		err = valid_line(buffer + i, j);
		if (err == VALID)
			insert_node(&head, buffer + i, j);
		else if (err == INVALID)
			return (NULL);
		i += j + 1;
	}
	return (head);
}

t_list	*read_file_and_build(char *filepath)
{
	int		file;
	int		size;
	char	buf[_BUF];

	file = open(filepath, O_RDONLY);
	if (file != -1)
	{
		size = read(file, buf, _BUF);
		if (size != 0)
			return (build_dict(buf, size));
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	t_list	*head;

	if (argc == 2)
		head = read_file_and_build(argv[1]);
	else
		head = read_file_and_build("../language_packs/numbers_en.dict");
	if (!head)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	ft_list_sort(&head, cmp_map);
	while (head)
	{
		printf("value = %lld, text = %s\n", head->data->value, head->data->text);
		head = head->next;
	}
	return (0);
}
