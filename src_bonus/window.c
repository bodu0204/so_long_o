#include"so_long.h"
void	base_win1(t_info	*i);

void	get_img(t_info	*i)
{
	int	buf;

	i->img_0 = mlx_xpm_file_to_image(i->mlx, FILE_0, &buf, &buf);
	i->img_1 = mlx_xpm_file_to_image(i->mlx, FILE_1, &buf, &buf);
	i->img_p[FRONT] = mlx_xpm_file_to_image(i->mlx, FILE_Pf, &buf, &buf);
	i->img_p[BACK] = mlx_xpm_file_to_image(i->mlx, FILE_Pb, &buf, &buf);
	i->img_p[LEFT] = mlx_xpm_file_to_image(i->mlx, FILE_Pl, &buf, &buf);
	i->img_p[RIGHT] = mlx_xpm_file_to_image(i->mlx, FILE_Pr, &buf, &buf);
	i->img_c = mlx_xpm_file_to_image(i->mlx, FILE_C, &buf, &buf);
	i->img_e = mlx_xpm_file_to_image(i->mlx, FILE_E, &buf, &buf);
	i->img_w[0] = i->img_0;
	i->img_w[1] = mlx_xpm_file_to_image(i->mlx, FILE_W01, &buf, &buf);
	i->img_w[2] = mlx_xpm_file_to_image(i->mlx, FILE_W02, &buf, &buf);
	i->img_w[3] = mlx_xpm_file_to_image(i->mlx, FILE_W03, &buf, &buf);
	i->img_w[4] = mlx_xpm_file_to_image(i->mlx, FILE_W04, &buf, &buf);
	i->img_w[5] = mlx_xpm_file_to_image(i->mlx, FILE_W05, &buf, &buf);
	i->img_w[6] = mlx_xpm_file_to_image(i->mlx, FILE_W06, &buf, &buf);
	i->img_w[7] = mlx_xpm_file_to_image(i->mlx, FILE_W07, &buf, &buf);
	i->img_w[8] = mlx_xpm_file_to_image(i->mlx, FILE_W08, &buf, &buf);
	i->img_w[9] = mlx_xpm_file_to_image(i->mlx, FILE_W09, &buf, &buf);
	i->img_w[10] = mlx_xpm_file_to_image(i->mlx, FILE_W10, &buf, &buf);
	return ;
}

void	set_win(t_info	*i)
{
	size_t	j;

	j = 0;
	while (i->map_c[j])
	{
		if (i->map_c[j] == 'C')
			mlx_put_image_to_window(i->mlx, i->win, i->img_c, \
			(j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		else if (i->map_c[j] == 'E')
			mlx_put_image_to_window(i->mlx, i->win, i->img_e, \
			(j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		else if (i->map_c[j] == 'W')
			mlx_put_image_to_window(i->mlx, i->win, i->img_w[9], \
			(j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		if (i->map_c[j] == 'P' || i->map_c[j] == 'W')
			i->map_c[j] = '0';
		else if (i->map_c[j] == 'M' || i->map_c[j] == 'F')
			i->map_c[j] = '1';
		j++;
	}
	mlx_put_image_to_window(i->mlx, i->win, i->img_p[BACK], \
	i->mp.nowx, i->mp.nowy);
	return ;
}

void	base_win(t_info	*i)
{
	size_t	j;
	int		buf;
	void	*img0;
	void	*img1;

	img0 = mlx_xpm_file_to_image(i->mlx, FILE_0b, &buf, &buf);
	img1 = mlx_xpm_file_to_image(i->mlx, FILE_1b, &buf, &buf);
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
	base_win1(i);
	return ;
}

void	base_win1(t_info	*i)
{
	int		buf;
	void	*img;

	if (i->mm)
	{
		img = mlx_xpm_file_to_image(i->mlx, FILE_M, &buf, &buf);
		mlx_put_image_to_window(i->mlx, i->win, img, \
		(i->mm % i->map_w) * BLOCKLEN, (i->mm / i->map_w) * BLOCKLEN);
		mlx_destroy_image(i->mlx, img);
	}
	if (i->mf)
	{
		img = mlx_xpm_file_to_image(i->mlx, FILE_F, &buf, &buf);
		mlx_put_image_to_window(i->mlx, i->win, img, \
		(i->mf % i->map_w) * BLOCKLEN, (i->mf / i->map_w) * BLOCKLEN);
		mlx_destroy_image(i->mlx, img);
	}
	return ;
}