/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwuthric <dwuthric@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:28:42 by dwuthric          #+#    #+#             */
/*   Updated: 2022/06/18 15:36:34 by dwuthric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
int	*parse(int argc, char **argv, int *n);
void	solve(int *input, int n);

int	main(int argc, char **argv)
{
	int	*board;
	int	n;

	n = 0;
	board = parse(argc, argv, &n);
	if (board == 0)
		ft_putstr("Error\n");
	else
		solve(board, n);
	return (0);
}


/*
int	main()
{
	int input[4][4] = { {4, 3, 2, 1},
						{1, 2, 2, 2},
						{4, 3, 2, 1},
						{1, 2, 2, 2} };

} "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
*/