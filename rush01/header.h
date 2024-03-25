/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:34:37 by marvin            #+#    #+#             */
/*   Updated: 2024/03/19 14:34:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_strlen(char *str);
int		main(int argc, char **argv);
int		ft_check_args(int argc, char **argv);
int		ft_size_tab(char **argv);
int		ft_good_number(char **argv, int size);
int		ft_backtrack(char *str, int size, char *argv);
int		ft_putstr_final(char *str, int size);
int		ft_check_vision_left(char *str, char *argv, int index, int size);
int		ft_check_vision_right(char *str, char *argv, int index, int size);
int		ft_check_vision_down(char *str, int index, int size, char *argv);
int		ft_check_vision_up(char *str, int index, int size, char *argv);
int		ft_check_collunm(char *str, int size, char *argv, int i);
int		ft_is_valid_collunm(char *str, int size, char *argv, int index);
int		ft_check_line(char *str, int size, char *argv, int i);
int		ft_is_valid_line(char *str, int size, char *argv, int index);

char	*ft_str_create(int size);
char	*ft_parsed_str(char *str, int size);
char	*ft_final_str_create(char *str);

void	ft_putstr(char *str, int sortie);

#endif