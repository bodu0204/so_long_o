/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:56:33 by kkohki            #+#    #+#             */
/*   Updated: 2022/03/23 23:14:51 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_map_size(t_info *info)
{
	size_t		fd;
	size_t		i;
	char		*line;

	i = 0;
	fd = open(info->map_info.filename, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		put_error("Error\nno data.\n");
	}
	info->map_info.x_size = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	info->map_info.y_size = i;
	return (0);
}

static int	file_to_array(t_info *info)
{
	char		*line;
	size_t		fd;
	size_t		i;

	info->map_info.map = malloc(sizeof(char *) * (info->map_info.y_size + 1));
	if (info->map_info.map == NULL)
		return (1);
	fd = open(info->map_info.filename, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] == '\n')
			put_error("Erorr\nmap error.\n");
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		info->map_info.map[i] = line;
		i++;
	}
	info->map_info.map[i] = NULL;
	close(fd);
	return (0);
}

int	read_map(t_info *info)
{
	count_map_size(info);
	if (file_to_array(info) != 0)
		return (1);
	return (0);
}

void	validate_enclose_wall(t_info *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < info->map_info.y_size)
	{
		j = 0;
		while (j < info->map_info.x_size)
		{
			if ((j == 0 || (j == info->map_info.x_size - 1)) \
			&& info->map_info.map[i][j] != '1')
			{
				ft_putstr_fd("Error\nno wall.\n", 2);
				free_element(info);
			}
			if ((i == 0 || i == info->map_info.y_size - 1) \
			&& info->map_info.map[i][j] != '1')
			{
				ft_putstr_fd("Error\nno wall.\n", 2);
				free_element(info);
			}
			j++;
		}
		i++;
	}
}

void	check_str(t_info	*info)
{
	char		*tmp_address;
	size_t		i;
	size_t		j;

	i = 0;
	while (i < info->map_info.y_size)
	{
		j = 0;
		while (j < info->map_info.x_size)
		{
			tmp_address = ft_strchr("10CEP", info->map_info.map[i][j]);
			if (tmp_address == NULL)
			{
				ft_putstr_fd("Error\nwrong map.\n", 2);
				free_element(info);
			}
			j++;
		}
		i++;
	}
}
