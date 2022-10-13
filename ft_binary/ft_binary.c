/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Karrar <kahamza@student.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:32:55 by Karrar            #+#    #+#             */
/*   Updated: 2022/10/13 10:16:56 by Karrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_reverse(char *arr)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	while (arr[j] != '\0')
	{
		j++;
	}
	tmp = 0;
	i = 0;
	while (i < (j / 2))
	{
		tmp = arr[i];
		arr[i] = arr[j - i - 1];
		arr[j - i - 1] = tmp;
		i++;
	}
}

void	ft_binary(char digits[32], int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		digits[i] = (num % 2) + '0';
		i++;
		num /= 2;
	}
	digits[i] = '\0';
	ft_reverse(digits);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int		i;
	int		number;
	char	digits[32];

	number = 10;
	ft_binary(digits, number);
	i = 0;
	while (digits[i] != '\0')
	{
		ft_putchar(digits[i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
