/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 05:20:50 by kkohki            #+#    #+#             */
/*   Updated: 2022/03/23 23:06:44 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	input_player_postion(t_info *info)
{
	size_t	x_i;
	size_t	y_i;
	size_t	player_flag;

	y_i = 0;
	player_flag = 0;
	while (info->map_info.map[y_i] != NULL)
	{
		x_i = 0;
		while (info->map_info.map[y_i][x_i] != '\0')
		{
			if (info->map_info.map[y_i][x_i] == 'P')
			{
				info->player.x_position = x_i;
				info->player.y_position = y_i;
				player_flag++;
			}
			x_i++;
		}
		y_i++;
	}
	if (player_flag != 1)
		return (1);
	return (0);
}

int	check_each_postion(t_info *info)
{
	size_t	x_i;
	size_t	y_i;
	size_t	c_flag;
	size_t	e_flag;

	y_i = 0;
	c_flag = 0;
	e_flag = 0;
	while (info->map_info.map[y_i] != NULL)
	{
		x_i = 0;
		while (info->map_info.map[y_i][x_i] != '\0')
		{
			if (info->map_info.map[y_i][x_i] == 'C')
				c_flag++;
			if (info->map_info.map[y_i][x_i] == 'E')
				e_flag++;
			x_i++;
		}
		y_i++;
	}
	info->num.c_flag_num = c_flag;
	if (!(c_flag > 0 && e_flag > 0))
		return (1);
	return (0);
}

void	check_len(t_info	*info)
{
	size_t	i;

	i = 0;
	while (i < info->map_info.y_size - 1)
	{
		if (ft_strlen(info->map_info.map[i]) != \
		ft_strlen(info->map_info.map[i + 1]))
		{
			ft_putstr_fd("Error\nnot rectangle.\n", 2);
			free_element(info);
		}
		i++;
	}
}
