/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:24:55 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/17 17:05:43 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_error(char *error_message, t_game *game)
{
	ft_printf("Error\n%s\n", error_message);
	destroy_window(game);
	exit(1);
}

void	download_images(t_game *game)
{
	int		width;
	int		height;

	game->img.astronaut = mlx_xpm_file_to_image(game->mlx,
			"images/astronaut.xpm", &width, &height);
	game->img.background = mlx_xpm_file_to_image(game->mlx,
			"images/background.xpm", &width, &height);
	game->img.planet = mlx_xpm_file_to_image(game->mlx,
			"images/planet.xpm", &width, &height);
	game->img.earth = mlx_xpm_file_to_image(game->mlx,
			"images/earth.xpm", &width, &height);
	game->img.blackhole = mlx_xpm_file_to_image(game->mlx,
			"images/blackhole.xpm", &width, &height);
	game->img.height = height;
	game->img.width = width;
}
