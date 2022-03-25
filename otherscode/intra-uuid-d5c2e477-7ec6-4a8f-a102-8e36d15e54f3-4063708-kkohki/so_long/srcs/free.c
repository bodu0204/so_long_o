/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:45:18 by kkohki            #+#    #+#             */
/*   Updated: 2022/03/15 23:07:18 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_double_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	free_element(t_info *info)
{
	if (info->map_info.map != NULL)
		free_double_array(info->map_info.map);
	if (info->image.empty != NULL)
		mlx_destroy_image(info->mlx, info->image.empty);
	if (info->image.exit != NULL)
		mlx_destroy_image(info->mlx, info->image.exit);
	if (info->image.collectable != NULL)
		mlx_destroy_image(info->mlx, info->image.collectable);
	if (info->image.player != NULL)
		mlx_destroy_image(info->mlx, info->image.player);
	if (info->image.wall != NULL)
		mlx_destroy_image(info->mlx, info->image.wall);
	if (info->window != NULL)
		mlx_destroy_window(info->mlx, info->window);
	exit (1);
	return (0);
}
