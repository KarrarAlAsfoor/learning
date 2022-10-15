/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Karrar <kahamza@student.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:58:22 by Karrar            #+#    #+#             */
/*   Updated: 2022/10/15 02:58:38 by Karrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(size_t nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
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
			ft_putnbr(matrix[i][j]);
			if (j < x - 1)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			j++;
		}
		ft_putchar(']');
		ft_putchar('\n');
		i++;
	}
}

int	main(void)
{
	size_t		m;
	size_t		n;
	size_t		i;
	int			**matrix;
	int			**rotated;

	m = 5;
	n = 8;
	matrix = malloc(sizeof(int *) * m);
	rotated = malloc(sizeof(int *) * n);
	i = 0;
	while (i < m)
	{
		matrix[i] = malloc(sizeof(int) * n);
		i++;
	}
	i = 0;
	while (i < n)
	{
		rotated[i] = malloc(sizeof(int) * m);
		i++;
	}
	ft_fill(matrix, m, n);
	write(1, "the matrix : ", 13);
	ft_putchar('\n');
	ft_print_matrix(matrix, m, n);
	ft_putchar('\n');
	rotate_matrix(m, n, matrix, rotated);
	write(1, "after being rotated : ", 22);
	ft_putchar('\n');
	ft_print_matrix(rotated, n, m);
	free (matrix);
	free (rotated);
	return (0);
}
