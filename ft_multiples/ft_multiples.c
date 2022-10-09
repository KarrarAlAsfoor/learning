/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiples.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Karrar <kahamza@student.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:11:55 by Karrar            #+#    #+#             */
/*   Updated: 2022/10/09 02:05:11 by Karrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	solution(int number)
{
	int	i;
	int	result;

	if (number <= 0)
		return (0);
	result = 0;
	i = 0;
	while (i < number)
	{
		if (i % 5 == 0 && i % 3 == 0)
		{
			result += i;
			i++;
		}
		else if (i % 5 == 0)
		{
			result += i;
		}
		else if (i % 3 == 0)
		{
			result += i;
		}
		i++;
	}
	return (result);
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
	ft_putnbr(solution(10));
	ft_putchar('\n');
	return (0);
}
