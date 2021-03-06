/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi </var/mail/mfujishi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:18:25 by mfujishi          #+#    #+#             */
/*   Updated: 2022/03/18 11:18:25 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "sl_config.h"

void	draw_enemy(t_sys *sys, int frame, t_map *map)
{
	size_t	i;

	(void)frame;
	i = 0;
	while (i < map->enemy)
	{
		draw_tex(&sys->img, &sys->enemy, \
		map->enemies[i].en_x * TEX_SIZE, map->enemies[i].en_y * TEX_SIZE);
		i++;
	}
}

void	draw_player(t_sys *sys, int frame, int n, int i)
{
	if (frame < ANIME_FRAME)
	{
		if (sys->pl_dir == KEY_W)
			draw_tex(&sys->img, &sys->player_up[0], n, i);
		else if (sys->pl_dir == KEY_A)
			draw_tex(&sys->img, &sys->player_left[0], n, i);
		else if (sys->pl_dir == KEY_S)
			draw_tex(&sys->img, &sys->player_down[0], n, i);
		else if (sys->pl_dir == KEY_D)
			draw_tex(&sys->img, &sys->player_right[0], n, i);
	}
	else
	{
		if (sys->pl_dir == KEY_W)
			draw_tex(&sys->img, &sys->player_up[1], n, i);
		else if (sys->pl_dir == KEY_A)
			draw_tex(&sys->img, &sys->player_left[1], n, i);
		else if (sys->pl_dir == KEY_S)
			draw_tex(&sys->img, &sys->player_down[1], n, i);
		else if (sys->pl_dir == KEY_D)
			draw_tex(&sys->img, &sys->player_right[1], n, i);
	}
}

void	draw_collect(t_sys *sys, int frame, int n, int i)
{
	if (frame < ANIME_FRAME)
		draw_tex(&sys->img, &sys->collect[0], n, i);
	else
		draw_tex(&sys->img, &sys->collect[1], n, i);
}

int	draw_map(t_map *map, t_img *img, t_sys *sys, int frame)
{
	size_t	i;
	size_t	n;

	i = 0;
	while (i < map->height)
	{
		n = 0;
		while (n < map->width)
		{
			draw_tex(img, &sys->tile, n * TEX_SIZE, i * TEX_SIZE);
			if (map->map[i][n] == '1')
				draw_tex(img, &sys->wall, n * TEX_SIZE, i * TEX_SIZE);
			else if (map->map[i][n] == 'C')
				draw_collect(sys, frame, n * TEX_SIZE, i * TEX_SIZE);
			else if (map->map[i][n] == 'E')
				draw_tex(img, &sys->goal, n * TEX_SIZE, i * TEX_SIZE);
			n++;
		}
		i++;
	}
	return (0);
}
