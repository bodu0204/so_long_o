/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_image_to_window.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:26:12 by kkohki            #+#    #+#             */
/*   Updated: 2022/03/18 04:48:04 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	allocate_image(t_info *info)
{
	int	tile_size;

	tile_size = 32;
	info->image.player = mlx_xpm_file_to_image(info->mlx, \
		"images/naruto.xpm", &tile_size, &tile_size);
	info->image.wall = mlx_xpm_file_to_image(info->mlx, \
		"images/wall.xpm", &tile_size, &tile_size);
	info->image.collectable = mlx_xpm_file_to_image(info->mlx, \
		"images/star.xpm", &tile_size, &tile_size);
	info->image.exit = mlx_xpm_file_to_image(info->mlx, \
		"images/exit.xpm", &tile_size, &tile_size);
	info->image.empty = mlx_xpm_file_to_image(info->mlx, \
		"images/empty.xpm", &tile_size, &tile_size);
}

static void	lexer_char(t_info *info, int x_i, int y_i)
{
	if (info->map_info.map[y_i][x_i] == '1')
		mlx_put_image_to_window(info->mlx, \
			info->window, info->image.wall, x_i * TILE_SIZE, y_i * TILE_SIZE);
	else if (info->map_info.map[y_i][x_i] == 'C')
		mlx_put_image_to_window(info->mlx, \
			info->window, info->image.collectable, \
				x_i * TILE_SIZE, y_i * TILE_SIZE);
	else if (info->map_info.map[y_i][x_i] == 'E')
		mlx_put_image_to_window(info->mlx, \
			info->window, info->image.exit, x_i * TILE_SIZE, y_i * TILE_SIZE);
	else if (info->map_info.map[y_i][x_i] == 'P')
		mlx_put_image_to_window(info->mlx, \
			info->window, info->image.player, x_i * TILE_SIZE, y_i * TILE_SIZE);
	else if (info->map_info.map[y_i][x_i] == '0')
		mlx_put_image_to_window(info->mlx, \
			info->window, info->image.empty, x_i * TILE_SIZE, y_i * TILE_SIZE);
}

void	assign_xpm_image(t_info *info)
{
	size_t	x_i;
	size_t	y_i;

	y_i = 0;
	while (y_i < info->map_info.y_size)
	{
		x_i = 0;
		while (x_i < info->map_info.x_size)
		{
			lexer_char(info, x_i, y_i);
			x_i++;
		}
		y_i++;
	}
}

void	create_window(t_info *info)
{
	info->mlx = mlx_init();
	info->window = mlx_new_window(info->mlx, \
		info->map_info.x_size * TILE_SIZE, \
			info->map_info.y_size * TILE_SIZE, "so_long");
	allocate_image(info);
	assign_xpm_image(info);
}
