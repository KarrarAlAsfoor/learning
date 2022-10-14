/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_diff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Karrar <kahamza@student.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 01:43:24 by Karrar            #+#    #+#             */
/*   Updated: 2022/10/14 16:50:46 by Karrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

size_t	ft_size(const int *arr1, size_t n1, const int *arr2, size_t n2)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = 0;
	i = 0;
	while (i < n1)
	{
		j = 0;
		while (j < n2)
		{
			if (arr1[i] == arr2[j])
			{
				break ;
			}
			j++;
		}
		if (j == n2)
		{
			size += 1;
		}
		i++;
	}
	return (size);
}

int	*array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z)
{
	size_t	i;
	size_t	j;
	size_t	d;
	int		*arr3;

	*z = ft_size(arr1, n1, arr2, n2);
	arr3 = malloc(sizeof(int) * (*z));
	i = 0;
	d = 0;
	while (i < n1)
	{
		j = 0;
		while (j < n2)
		{
			if (arr1[i] == arr2[j])
			{
				break ;
			}
			j++;
		}
		if (j == n2)
		{
			arr3[d] = arr1[i];
			d++;
		}
		i++;
	}
	return (arr3);
	free (arr3);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}

int	main(void)
{
	const int	arr1[] = {1, 2, 2, 2, 3};
	size_t		n1;
	const int	arr2[] = {2};
	size_t		n2;
	size_t		*z;
	size_t		size;
	size_t		i;

	size = 0;
	z = &size;
	n1 = 5;
	n2 = 1;
	array_diff(arr1, n1, arr2, n2, z);
	write(1, "size is : ", 10);
	ft_putnbr(size);
	ft_putchar('\n');
	write(1, "values are : ", 13);
	i = 0;
	while (i < size)
	{
		ft_putnbr(array_diff(arr1, n1, arr2, n2, z)[i]);
		if (i < (size - 1))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		i++;
	}
	ft_putchar('\n');
	return (0);
}
