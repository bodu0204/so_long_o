/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 13:51:46 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/17 17:05:00 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	safe_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.row)
	{
		safe_free(&game->map.content[i]);
		i++;
	}
	safe_free(game->map.content);
}

int	destroy_window(t_game *game)
{
	if (game->win != NULL)
	{
		mlx_destroy_image(game->mlx, game->img.background);
		mlx_destroy_image(game->mlx, game->img.blackhole);
		mlx_destroy_image(game->mlx, game->img.planet);
		mlx_destroy_image(game->mlx, game->img.astronaut);
		mlx_destroy_image(game->mlx, game->img.earth);
		mlx_destroy_window(game->mlx, game->win);
	}
	if (game->map.str != NULL)
		safe_free(&game->map.str);
	if (game->map.content != NULL)
		free_map(game);
	exit(0);
}
