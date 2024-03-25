/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norminette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:25:37 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 14:25:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_check_vision_left(char *str, char *argv, int index, int size)
{
	int		line;
	char	vision;
	int		i;
	char	buff;

	i = 0;
	vision = '0';
	buff = '0';
	line = index / size - 1;
	while (index - i + line > index - size)
	{
		if (str[index - 1 - i] > buff)
		{
			buff = str[index - i - 1];
			vision++;
		}
		i++;
	}
	if (argv[(size * 4) - size + line] != vision)
		return (0);
	return (1);
}

int	ft_check_vision_right(char *str, char *argv, int index, int size)
{
	int		line;
	char	vision;
	int		i;
	char	buff;

	i = 0;
	vision = '0';
	buff = '0';
	line = index / size - 1;
	while (index - size + i < index)
	{
		if (str[index - size + i] > buff)
		{
			buff = str[index - size + i];
			vision++;
		}
		i++;
	}
	if (argv[(size * 4) - (size * 2) + line] != vision)
		return (0);
	return (1);
}

int	ft_check_vision_down(char *str, int index, int size, char *argv)
{
	int		collunm;
	char	vision;
	int		i;
	char	buff;

	i = 0;
	vision = '0';
	buff = '0';
	collunm = (index - 1) % size;
	while (index - 1 - i >= 0)
	{
		if (str[index - 1 - i] > buff)
		{
			buff = str[index - 1 - i];
			vision++;
		}
		i += size;
	}
	if (argv[size + collunm] != vision)
		return (0);
	return (1);
}

int	ft_check_vision_up(char *str, int index, int size, char *argv)
{
	int		collunm;
	char	vision;
	int		i;
	char	buff;

	i = 0;
	vision = '0';
	buff = '0';
	collunm = (index - 1) % size;
	while (collunm + i <= size * size)
	{
		if (str[collunm + i] > buff)
		{
			buff = str[collunm + i];
			vision++;
		}
		i += size;
	}
	if (argv[collunm] != vision)
		return (0);
	return (1);
}

int	ft_check_collunm(char *str, int size, char *argv, int i)
{
	if (ft_is_valid_collunm(str, size, argv, i) == 0)
	{
		--i;
		str[i]++;
		if (str[i] > size + '0')
		{
			str[i] = '1';
			--i;
			str[i]++;
		}
	}
	return (i);
}
