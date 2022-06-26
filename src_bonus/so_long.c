#include"so_long.h"

int	main(int argc, char *argv[])
{
	t_info	i;

	ft_bzero(&i, sizeof(t_info));
	i.newkey = NO_KEY;
	check_arg(argc, argv);
	get_map(&i, argv[1]);
	i.mlx = mlx_init();
	i.win = mlx_new_window(i.mlx, i.map_w * BLOCKLEN, \
	i.map_h * BLOCKLEN, "so_long");
	get_img(&i);
	base_win(&i);
	set_win(&i);
	mlx_loop_hook(i.mlx, game_main, &i);
	mlx_hook(i.win, 2, 0, set_key, &i);
	mlx_hook(i.win, 3, 0, rm_key, &i);
	mlx_hook(i.win, 17, 0, end_game, &i);
	mlx_loop(i.mlx);
	return (0);
}

void	check_arg(int argc, char *argv[])
{
	if (argc < 2)
		error_exit("No map!\n");
	if (argc > 2)
		error_exit("Too many maps!\n");
	if (ft_strlen(argv[1]) < 4)
		error_exit("Invalid format!\n");
	if (ft_memcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		error_exit("Invalid format!\n");
	return ;
}
