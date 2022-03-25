/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 05:20:46 by kkohki            #+#    #+#             */
/*   Updated: 2022/03/24 01:51:23 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen((char *)s) + 1;
	while (i--)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
	}
	return (NULL);
}

void	put_error(char *str)
{
	ssize_t	i;

	i = write(1, str, ft_strlen(str));
	if (i == -1)
		return ;
	exit(1);
}

void	error_check(t_info	*info)
{
	if (read_map(info) != 0)
	{
		ft_putstr_fd("Erorr\nmalloc error.\n", 2);
		free_element(info);
	}
	if (input_player_postion(info) != 0)
	{
		ft_putstr_fd("Erorr\ninvlid players.\n", 2);
		free_element(info);
	}
	if (check_each_postion(info) != 0)
	{
		ft_putstr_fd("Erorr\nwrong map.\n", 2);
		free_element(info);
	}
	validate_enclose_wall(info);
	check_str(info);
	check_len(info);
}

int	main(int argc, char **argv)
{
	static t_info	info = {};
	char			*ptr;
	char			*ptr_2;

	if (argc != 2)
		put_error("Error\ninvalid argument.\n");
	info.map_info.filename = argv[1];
	error_check(&info);
	ptr = ft_strrchr(argv[1], '.');
	ptr_2 = ft_strrchr(argv[1], '/');
	if (ft_strncmp(ptr, ".ber", 5) != 0)
		put_error("Error\nwrong name.\n");
	if (ft_strncmp(ptr_2, "/.ber", 6) == 0)
		put_error("Error\nwrong name.\n");
	create_window(&info);
	set_event(&info);
	mlx_loop(info.mlx);
	return (0);
}
