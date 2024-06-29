#include "cub3d.h"

void	game(t_cub3d *info)
{
// draw.c
	draw_loop(&info->mlx_info, &info->map_info, &info->player_info);
	mlx_put_image_to_window(info->mlx_info.mlx, info->mlx_info.mlx_win, info->mlx_info.img_data.img, 0, 0);
}
