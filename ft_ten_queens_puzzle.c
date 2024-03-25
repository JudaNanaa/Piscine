/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:25:44 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 21:27:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_is_valid(char *str, int index)
{
	int	i;

	i = 1;
	while (index - i >= 0)
	{
		if (str[index] == str[index - i++])
			return (0);
	}
	i = -1;
	while (str[index] - ++i - 1 >= '0')
	{
		if (str[index] - i - 1 == str[index - 1 - i])
			return (0);
	}
	i = -1;
	while (str[index] + ++i + 1 <= '9')
	{
		if (str[index] + i + 1 == str[index - 1 - i])
			return (0);
	}
	return (1);
}

int	ft_norminette(char *str, int i, int result)
{
	i = 0;
	while (i < 10)
	{
		while (ft_is_valid(str, i) == 0 && str[i] <= '9')
			str[i]++;
		if (str[i] > '9')
		{
			if (i == 0)
				return (result);
			str[i] = '0';
			i--;
			str[i]++;
		}
		else
			i++;
	}
	write(1, str, 10);
	write(1, "\n", 1);
	str[9]++;
	while (str[0] <= '9')
		result = ft_norminette(str, i, ++result);
	return (result);
}

int	ft_ten_queens_puzzle(void)
{
	char	str[10];
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (i < 10)
		str[i++] = '0';
	result = ft_norminette(str, i, result);
	return (result);
}

/*int main(void)
{
	printf("%d\n", ft_ten_queens_puzzle());
}*/