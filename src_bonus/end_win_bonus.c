/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_win_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:18:33 by ryoakira          #+#    #+#             */
/*   Updated: 2022/06/26 20:18:34 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	success_win(t_info *i)
{
	size_t	x;
	size_t	y;
	void	*img;
	int		buf;

	frree_content(i);
	x = i->map_w * BLOCKLEN;
	y = i->map_h * BLOCKLEN;
	if (x < 300)
		x = 0;
	else
		x = (x - 300) / 2;
	if (y < 300)
		y = 0;
	else
		y = (y - 300) / 2;
	img = mlx_xpm_file_to_image(i->mlx, FILE_HAPPY, &buf, &buf);
	mlx_put_image_to_window(i->mlx, i->win, img, x, y);
	mlx_destroy_image(i->mlx, img);
	return ;
}

void	fale_win(t_info *i)
{
	size_t	x;
	size_t	y;
	void	*img;
	int		buf;

	frree_content(i);
	x = i->map_w * BLOCKLEN;
	y = i->map_h * BLOCKLEN;
	if (x < 300)
		x = 0;
	else
		x = (x - 300) / 2;
	if (y < 300)
		y = 0;
	else
		y = (y - 300) / 2;
	img = mlx_xpm_file_to_image(i->mlx, FILE_BAD, &buf, &buf);
	mlx_put_image_to_window(i->mlx, i->win, img, x, y);
	mlx_destroy_image(i->mlx, img);
	return ;
}
