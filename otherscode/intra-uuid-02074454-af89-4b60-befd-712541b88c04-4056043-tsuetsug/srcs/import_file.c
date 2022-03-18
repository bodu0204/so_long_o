/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:25:50 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/17 17:10:18 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	read_file(char *file_name, t_game *game)
{
	int		fd;
	char	buff[32767];
	int		rc;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("File open error", game);
	rc = read(fd, buff, 32766);
	if (rc == -1)
		ft_error("File read error", game);
	else if (rc == 0)
		ft_error("No content", game);
	else
		buff[rc] = '\0';
	close(fd);
	game->map.str = ft_strdup(buff);
}

void	sizeof_col_row(t_game *game)
{
	int	prev_col;
	int	i;

	i = 0;
	prev_col = 0;
	game->map.col = 0;
	game->map.row = 0;
	while (game->map.str[i])
	{
		game->map.col = 0;
		while (game->map.str[i] && (game->map.str[i] != '\n'))
		{
			game->map.col++;
			i++;
		}
		if (prev_col && (game->map.col != prev_col))
			ft_error("Col length is not same, map is not rectangular", game);
		prev_col = game->map.col;
		i++;
		game->map.row++;
	}
	if ((game->map.col < 3 && game->map.row < 5)
		|| (game->map.col < 5 && game->map.row < 3))
		ft_error("Map is too small", game);
}

void	convert_map_2D_array(t_game *game)
{
	int		i;
	int		k;

	game->map.content = malloc(sizeof(char *) * (game->map.row));
	if (!game->map.content)
		ft_error("Map is not allocated", game);
	i = 0;
	k = 0;
	while (i < game->map.row)
	{
		game->map.content[i] = malloc(sizeof(char) * (game->map.col + 1));
		if (!game->map.content[i])
			ft_error("Map content is not allocated", game);
		ft_strlcpy(game->map.content[i], &game->map.str[k], game->map.col + 1);
		i++;
		k = k + game->map.col + 1;
	}
}

void	save_player_start_position(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < game->map.row)
	{
		while (x < game->map.col)
		{
			if (game->map.content[y][x] == 'P')
			{
				game->map.player_x = x;
				game->map.player_y = y;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_error("There is no P!", game);
}

void	import_map(char *file_name, t_game *game)
{
	validate_file_name(file_name, game);
	read_file(file_name, game);
	sizeof_col_row(game);
	convert_map_2D_array(game);
	save_player_start_position(game);
	validate_map_components(game);
}
