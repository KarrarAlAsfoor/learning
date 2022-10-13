/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sumodds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Karrar <kahamza@student.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:35:06 by Karrar            #+#    #+#             */
/*   Updated: 2022/10/14 00:39:17 by Karrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <inttypes.h>

uint64_t	ft_sumodds(uint32_t n)
{
	uint64_t	sum;

	sum = (uint64_t) n * n * n;
	return (sum);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(uint64_t nb)
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

int	main(void)
{
	ft_putnbr(ft_sumodds(2231713));
	ft_putchar('\n');
	return (0);
}
