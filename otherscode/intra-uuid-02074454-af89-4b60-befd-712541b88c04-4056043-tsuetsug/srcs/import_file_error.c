/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_file_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:27:09 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/17 21:44:38 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	validate_file_name(char *file_name, t_game *game)
{
	if (ft_strncmp(file_name, ".ber\0", 5) == 0)
		ft_error("File type is only .ber", game);
	while (*file_name)
	{
		if ((*file_name == '/') && ft_strncmp(file_name, "/.ber\0", 6) == 0)
			ft_error("File type is only .ber", game);
		else if ((*file_name == '.') && ft_strncmp(file_name, ".ber\0", 5) != 0)
			ft_error("File type is not .ber", game);
		file_name++;
	}
}

void	validate_wall(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < game->map.col)
	{
		if (game->map.content[0][j] != '1')
			ft_error("Top wall has a hole", game);
		else if (game->map.content[(game->map.row) - 1][j] != '1')
			ft_error("Bottom wall has a hole", game);
		j++;
	}
	while (i < game->map.row)
	{
		if (game->map.content[i][0] != '1')
			ft_error("Left wall has a hole", game);
		else if (game->map.content[i][(game->map.col) - 1] != '1')
			ft_error("Right wall has a hole", game);
		i++;
	}
}

int	count_map_components(char map_components, t_game *game)
{
	int		i;
	int		j;
	int		char_count;

	i = 0;
	j = 0;
	char_count = 0;
	while (i < game->map.row)
	{
		while (j < game->map.col)
		{
			if (game->map.content[i][j] == map_components)
				char_count++;
			j++;
		}
		i++;
		j = -1;
	}
	return (char_count);
}

void	validate_map_components(t_game *game)
{
	int		p_count;
	int		e_count;
	int		c_count;

	p_count = count_map_components('P', game);
	if (p_count != 1)
		ft_error("Player count is invalid", game);
	e_count = count_map_components('E', game);
	if (e_count < 1)
		ft_error("Map exit count is invalid", game);
	c_count = count_map_components('C', game);
	if (c_count < 1)
		ft_error("Collectible count is invalid", game);
	validate_wall(game);
}
