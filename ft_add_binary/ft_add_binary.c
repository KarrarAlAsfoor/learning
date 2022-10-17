/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Karrar <kahamza@student.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:11:57 by Karrar            #+#    #+#             */
/*   Updated: 2022/10/17 02:14:11 by Karrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// fixed commit name

#include <unistd.h>
#include <stdint.h>

void	ft_reverse(char *binary, unsigned int j)
{
	unsigned int	i;
	char			tmp;

	i = 0;
	while (i < (j / 2))
	{
		tmp = binary[i];
		binary[i] = binary[j - i - 1];
		binary[j - i - 1] = tmp;
		i++;
	}
	binary[j] = '\0';
}

char	*binary_add(unsigned a, unsigned b, char *binary)
{
	uint64_t		c;
	unsigned int	j;

	c = (uint64_t)a + b;
	j = 0;
	while (c != 0)
	{
		binary[j] = c % 2 + '0';
		j++;
		c /= 2;
	}
	if (j > 0)
	{
		ft_reverse(binary, j);
	}
	if (a + b == 0)
	{
		binary[0] = '0';
		binary[1] = '\0';
	}
	return (binary);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	int				i;
	char			str[200];
	unsigned long	num1;
	unsigned long	num2;

	num1 = 4294967295;
	num2 = 4294967295;
	i = 0;
	while (binary_add(num1, num2, str)[i] != '\0')
	{
		ft_putchar(binary_add(num1, num2, str)[i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
