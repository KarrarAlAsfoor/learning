/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basicop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Karrar <kahamza@student.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 23:04:28 by Karrar            #+#    #+#             */
/*   Updated: 2022/10/31 23:32:42 by Karrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	basic_op(char op, int value1, int value2)
{
	int	result;

	result = 0;
	if (op == '+')
		result = value1 + value2;
	else if (op == '-')
		result = value1 - value2;
	else if (op == '*')
		result = value1 * value2;
	else if (op == '/')
		result = value1 / value2;
	return (result);
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
		ft_putstr("-2");
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
		ft_putnbr(nb);
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
	ft_putstr("result is : ");
	ft_putnbr(basic_op('/', 10, 5));
	ft_putchar('\n');
	return (0);
}
