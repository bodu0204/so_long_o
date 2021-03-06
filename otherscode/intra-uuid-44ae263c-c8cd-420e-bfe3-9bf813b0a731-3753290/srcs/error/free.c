/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi </var/mail/mfujishi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:18:35 by mfujishi          #+#    #+#             */
/*   Updated: 2022/03/18 11:18:35 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "sl_error.h"

void	free_reading_map(char **map, size_t height)
{
	size_t	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	free_enemy(t_map *map)
{
	free(map->enemies);
}
