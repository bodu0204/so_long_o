/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seting.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:17:53 by ryoakira          #+#    #+#             */
/*   Updated: 2022/06/26 20:17:54 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"
void	set_win1(t_info	*i);

void	get_img(t_info	*i)
{
	int	buf;

	i->img_0 = mlx_xpm_file_to_image(i->mlx, FILE_0, &buf, &buf);
	i->img_p = mlx_xpm_file_to_image(i->mlx, FILE_P, &buf, &buf);
	return ;
}

void	set_win(t_info	*i)
{
	size_t	j;
	int		buf;
	void	*img0;
	void	*img1;

	img0 = mlx_xpm_file_to_image(i->mlx, FILE_0B, &buf, &buf);
	img1 = mlx_xpm_file_to_image(i->mlx, FILE_1B, &buf, &buf);
	j = 0;
	while (i->map_c[j])
	{
		if (i->map_c[j] == '1')
			mlx_put_image_to_window(i->mlx, i->win, img1, \
			(j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		else
			mlx_put_image_to_window(i->mlx, i->win, img0, \
			(j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		j++;
	}
	mlx_destroy_image(i->mlx, img0);
	mlx_destroy_image(i->mlx, img1);
	set_win1(i);
	return ;
}

void	set_win1(t_info	*i)
{
	size_t	j;
	int		buf;
	void	*imgc;
	void	*imge;

	imgc = mlx_xpm_file_to_image(i->mlx, FILE_C, &buf, &buf);
	imge = mlx_xpm_file_to_image(i->mlx, FILE_E, &buf, &buf);
	j = 0;
	while (i->map_c[j])
	{
		if (i->map_c[j] == 'C')
			mlx_put_image_to_window(i->mlx, i->win, imgc, \
			(j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		else if (i->map_c[j] == 'E')
			mlx_put_image_to_window(i->mlx, i->win, imge, \
			(j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		j++;
	}
	mlx_destroy_image(i->mlx, imgc);
	mlx_destroy_image(i->mlx, imge);
	mlx_put_image_to_window(i->mlx, i->win, i->img_p, \
	(i->mc % i->map_w) * BLOCKLEN, (i->mc / i->map_w) * BLOCKLEN);
}
