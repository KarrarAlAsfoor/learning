/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findtheodd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Karrar <kahamza@student.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 02:33:27 by Karrar            #+#    #+#             */
/*   Updated: 2022/10/17 04:30:23 by Karrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

int	find_odd(size_t length, const int array[length])
{
	size_t	i;
	size_t	j;
	int		count;

	i = 0;
	while (i < length)
	{
		count = 0;
		j = 0;
		while (j < length)
		{
			if (array[i] == array[j])
			{
				count += 1;
			}
			j++;
		}
		if (count % 2 != 0)
		{
			break ;
		}
		i++;
	}
	return (array[i]);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
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
	int		array[5];
	size_t	length;

	array[0] = 1;
	array[1] = 1;
	array[2] = 8;
	array[3] = -33;
	array[4] = -33;
	length = 5;
	ft_putstr("\n");
	ft_putnbr(find_odd(length, array));
	ft_putstr("\n\n");
	return (0);
}
