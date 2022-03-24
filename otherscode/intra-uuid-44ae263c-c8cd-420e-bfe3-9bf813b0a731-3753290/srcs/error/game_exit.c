/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi </var/mail/mfujishi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:18:35 by mfujishi          #+#    #+#             */
/*   Updated: 2022/03/18 11:18:35 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	success_exit(t_sys *sys, t_map *map)
{
	free_map(map);
	free_enemy(map);
	destroy_texture(sys);
	if (sys->win != NULL)
		mlx_destroy_window(sys->mlx, sys->win);
	if (sys->mlx != NULL)
		mlx_destroy_display(sys->mlx);
	free(sys->mlx);
	exit(0);
}

void	mlx_error_exit(t_sys *sys, t_map *map)
{
	free_map(map);
	free_enemy(map);
	destroy_texture(sys);
	if (sys->win != NULL)
		mlx_destroy_window(sys->mlx, sys->win);
	if (sys->mlx != NULL)
		mlx_destroy_display(sys->mlx);
	free(sys->mlx);
	exit(1);
}
