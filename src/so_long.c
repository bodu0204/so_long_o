/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:17:59 by ryoakira          #+#    #+#             */
/*   Updated: 2022/10/08 15:04:56 by blyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	main(int argc, char *argv[])
{
	t_info	i;

	ft_bzero(&i, sizeof(t_info));
	i.walk = 1;
	get_map(&i, argc, argv);
	i.mlx = mlx_init();
	i.win = mlx_new_window(i.mlx, i.map_w * BLOCKLEN, \
	i.map_h * BLOCKLEN, "so_long");
	get_img(&i);
	set_win(&i);
	mlx_loop_hook(i.mlx, game_process, &i);
	mlx_hook(i.win, 2, 0, set_key, &i);
	mlx_hook(i.win, 3, 0, rm_key, &i);
	mlx_hook(i.win, 17, 0, end_game, &i);
	mlx_loop(i.mlx);
	return (0);
}
