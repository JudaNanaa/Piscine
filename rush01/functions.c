/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:16:19 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 14:16:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int sortie)
{
	write(sortie, str, ft_strlen(str));
	write(sortie, "\n", 1);
}

int	ft_putstr_final(char *s, int size)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_final_str_create(s);
	if (str == NULL)
		return (0);
	while (str[i])
	{
		write(1, &str[i], (ft_strlen(str) / size) - 1);
		write(1, "\n", 1);
		i += ft_strlen(str) / size;
	}
	free(str);
	return (1);
}

char	*ft_final_str_create(char *str)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (ft_strlen(str) * 2 + 1));
	if (dest == NULL)
		return (NULL);
	while (str[i])
	{
		if (j % 2 == 0)
			dest[j++] = str[i++];
		if (j % 2 == 1)
			dest[j++] = ' ';
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_str_create(int size)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (size * size + 1));
	if (str == NULL)
		return (NULL);
	while (i < size * size)
		str[i++] = '1';
	str[i] = '\0';
	return (str);
}
