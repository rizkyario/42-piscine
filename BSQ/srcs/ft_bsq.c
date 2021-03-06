/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 13:19:15 by rnugroho          #+#    #+#             */
/*   Updated: 2017/08/23 13:19:15 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_count_obstacle(int **board, int nrow, int ncol)
{
	int i;
	int j;
	int l;
	int t;

	i = 0;
	while (++i < nrow)
		board[i][0] += board[i - 1][0];
	i = 0;
	while (++i < ncol)
		board[0][i] += board[0][i - 1];
	i = 1;
	while (i < nrow)
	{
		j = 1;
		while (j < ncol)
		{
			l = board[i][j - 1];
			t = board[i - 1][j];
			board[i][j] += l + t - board[i - 1][j - 1];
			j++;
		}
		i++;
	}
}

int		ft_input_to_array(char **str, int ***board, int dim[2], char *map_char)
{
	int i;
	int j;

	if (map_char[0] == map_char[1] || map_char[1] == map_char[2])
		return (0);
	if (map_char[2] == map_char[0])
		return (0);
	i = 0;
	while (i < dim[0])
	{
		j = 0;
		(*board)[i] = (int*)malloc(sizeof(int) * (dim[1]));
		while (j < dim[1])
		{
			if (str[i][j] == map_char[0])
				(*board)[i][j] = 0;
			else if (str[i][j] == map_char[1])
				(*board)[i][j] = 1;
			else
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_add_solution(char **tab_string, int solution[3], char *map_char)
{
	int i;
	int j;

	i = solution[0];
	while (i < solution[0] + solution[2])
	{
		j = solution[1];
		while (j < solution[1] + solution[2])
		{
			tab_string[i][j] = map_char[2];
			j++;
		}
		i++;
	}
}

int		ft_get_obstacle(int **board, int pos[2], int size, int **solution)
{
	int corner[4];
	int obs;

	if (pos[0] > 0 && pos[1] > 0)
		corner[0] = board[pos[0] - 1][pos[1] - 1];
	else
		corner[0] = 0;
	if (pos[0] > 0)
		corner[1] = board[pos[0] - 1][pos[1] + size - 1];
	else
		corner[1] = 0;
	if (pos[1] > 0)
		corner[2] = board[pos[0] + size - 1][pos[1] - 1];
	else
		corner[2] = 0;
	corner[3] = board[pos[0] + size - 1][pos[1] + size - 1];
	obs = corner[3] - corner[2] - corner[1] + corner[0];
	if ((*solution)[2] < size && obs == 0)
	{
		(*solution)[0] = pos[0];
		(*solution)[1] = pos[1];
		(*solution)[2] = size;
	}
	return (obs);
}
