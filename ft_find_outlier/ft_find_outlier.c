/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_outlier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Karrar <kahamza@student.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:22:24 by Karrar            #+#    #+#             */
/*   Updated: 2022/10/09 23:42:56 by Karrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_find_mod(const int *values)
{
	int	mod;

	mod = 0;
	if (values[0] % 2 == values[1] % 2)
	{
		mod = values[0] % 2;
	}
	else if (values[0] % 2 == values[2] % 2)
	{
		mod = values[0] % 2;
	}
	else if (values[1] % 2 == values[2] % 2)
	{
		mod = values[1] % 2;
	}
	if (mod < 0)
	{
		mod *= -1;
	}
	return (mod);
}

int	find_outlier(const int *values, size_t count)
{
	size_t	i;
	int		mod;
	int		tmp;

	mod = ft_find_mod(values);
	tmp = 0;
	i = 0;
	while (i <= count)
	{
		tmp = values[i];
		if (tmp < 0)
		{
			tmp *= -1;
		}
		if (tmp % 2 != mod)
		{
			break ;
		}
		i++;
	}
	return (values[i]);
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
	int	values[11];

	values[0] = 2;
	values[1] = 6;
	values[2] = 8;
	values[3] = 2;
	values[4] = -66;
	values[5] = 34;
	values[6] = -35;
	values[7] = 66;
	values[8] = 700;
	values[9] = 1002;
	values[10] = '\0';
	ft_putnbr(find_outlier(values, 10));
	ft_putchar('\n');
	return (0);
}
