#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_cub3d	info;

// arg.c
	is_arg_valid(argc, argv);
// get_map.c
	get_map_info(&info.map_info, argv[1]);
// get_player.c
	get_player_initial_info(&info.player_info, &info.map_info);
// init.c
	initialize_mlx(&info.mlx_info);
// draw.c
	game(&info);
// hook and loop
	mlx_hook(info.mlx_info.mlx_win, 2, 0, event_handler, &info);
	mlx_loop(info.mlx_info.mlx);
}
