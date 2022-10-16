/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalidwalk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Karrar <kahamza@student.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 23:46:16 by Karrar            #+#    #+#             */
/*   Updated: 2022/10/17 00:35:49 by Karrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

bool	isvalidwalk(const char *walk)
{
	int		i;
	int		ns;
	int		we;
	bool	validwalk;

	validwalk = false;
	ns = 0;
	we = 0;
	i = 0;
	while (walk[i] != '\0')
	{
		if (walk[i] == 'n')
			ns += 1;
		else if (walk[i] == 's')
			ns -= 1;
		else if (walk[i] == 'w')
			we += 1;
		else if (walk[i] == 'e')
			we -= 1;
		i++;
	}
	if (i == 10 && ns == 0 && we == 0)
		validwalk = true;
	return (validwalk);
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

int	main(void)
{
	char	*str;

	str = "nsnsnsnsns";
	if (isvalidwalk(str) == true)
	{
		ft_putstr("\nit is a valid walk.\n\n");
	}
	else if (isvalidwalk(str) == false)
	{
		ft_putstr("\nit is not a valid walk.\n\n");
	}
	return (0);
}
