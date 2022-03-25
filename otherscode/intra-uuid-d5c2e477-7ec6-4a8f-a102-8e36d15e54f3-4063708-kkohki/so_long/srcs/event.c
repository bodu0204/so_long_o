/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:42:34 by kkohki            #+#    #+#             */
/*   Updated: 2022/03/23 22:39:01 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	swap_tile(t_info *info, int next_x, int next_y)
{
	if (info->map_info.map[next_y][next_x] == '1')
		return ;
	if (info->map_info.map[next_y][next_x] == 'C')
		info->num.c_num++;
	if (info->map_info.map[next_y][next_x] == 'E')
	{
		if (info->num.c_num == info->num.c_flag_num)
		{
			ft_putstr_fd("game clear!\n", 1);
			free_element(info);
			exit(1);
		}
		return ;
	}
	info->map_info.map[next_y][next_x] = 'P';
	info->map_info.map[info->player.y_position][info->player.x_position] = '0';
	info->num.move_num++;
	ft_putstr_fd("The number of moves: ", 1);
	ft_putnbr_fd(info->num.move_num, 1);
	ft_putstr_fd("\n", 1);
}

void	move_player(t_info *info, int keycode)
{
	if (keycode == KEY_A)
		swap_tile(info, info->player.x_position - 1, info->player.y_position);
	else if (keycode == KEY_D)
		swap_tile(info, info->player.x_position + 1, info->player.y_position);
	else if (keycode == KEY_S)
		swap_tile(info, info->player.x_position, info->player.y_position + 1);
	else if (keycode == KEY_W)
		swap_tile(info, info->player.x_position, info->player.y_position - 1);
	else if (keycode == KEY_ESC)
	{
		free_element(info);
		exit(EXIT_FAILURE);
	}
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == KEY_A || keycode == KEY_D || keycode == KEY_S \
		|| keycode == KEY_W || keycode == KEY_ESC)
		move_player(info, keycode);
	input_player_postion(info);
	assign_xpm_image(info);
	return (0);
}

static int	click_exit(t_info *info)
{
	(void)info;
	exit(1);
	return (0);
}

void	set_event(t_info *info)
{
	mlx_hook(info->window, 2, 1L << 0, key_hook, info);
	mlx_hook(info->window, 17, 1L << 17, click_exit, info);
}
