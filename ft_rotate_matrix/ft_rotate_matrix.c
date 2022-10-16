/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Karrar <kahamza@student.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:58:22 by Karrar            #+#    #+#             */
/*   Updated: 2022/10/16 22:27:48 by Karrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "ft_put.h"

void	rotate_matrix(size_t m, size_t n, int **matrix, int **rotated)
{
	size_t	i;
	size_t	j;
	size_t	d;

	d = n - 1;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			rotated[i][j] = matrix[j][d];
			j++;
		}
		d--;
		i++;
	}
}

void	ft_fill(int **matrix, size_t y, size_t x)
{
	size_t	i;
	size_t	j;
	size_t	d;

	d = 1;
	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			matrix[i][j] = d;
			d += 1;
			j++;
		}
		i++;
	}
}

void	ft_print_matrix(int **matrix, size_t y, size_t x)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < y)
	{
		ft_putchar('[');
		j = 0;
		while (j < x)
		{
			if (matrix[i][j] < 10)
			{
				ft_putnbr(0);
			}
			ft_putnbr(matrix[i][j]);
			if (j < x - 1)
			{
				ft_putstr(", ");
			}
			j++;
		}
		ft_putstr("]\n");
		i++;
	}
}

void	ft_create_matrix(int **matrix, size_t y, size_t x)
{
	size_t	i;

	i = 0;
	while (i < y)
	{
		matrix[i] = malloc(sizeof(int) * x);
		i++;
	}
}

int	main(void)
{
	size_t		m;
	size_t		n;
	int			**matrix;
	int			**rotated;

	m = 5;
	n = 8;
	matrix = malloc(sizeof(int *) * m);
	rotated = malloc(sizeof(int *) * n);
	ft_create_matrix(matrix, m, n);
	ft_create_matrix(rotated, n, m);
	ft_fill(matrix, m, n);
	ft_putstr("\nthe matrix : \n\n");
	ft_print_matrix(matrix, m, n);
	ft_putchar('\n');
	rotate_matrix(m, n, matrix, rotated);
	ft_putstr("after being rotated : \n\n");
	ft_print_matrix(rotated, n, m);
	ft_putchar('\n');
	free (matrix);
	free (rotated);
	return (0);
}
