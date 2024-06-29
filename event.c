#include "cub3d.h"

static void	render_next_image(t_mlx_info *mlx_info, t_cub3d *info)
{
	mlx_info->img_data.img
		= mlx_new_image(mlx_info->mlx, mlx_info->win_width,
			mlx_info->win_height);
	mlx_info->img_data.addr
		= mlx_get_data_addr(mlx_info->img_data.img,
			&mlx_info->img_data.bits_per_pixel,
			&mlx_info->img_data.line_length, &mlx_info->img_data.endian);
	game(info);
}

int	event_handler(int keycode, t_cub3d *info)
{
	t_data	*tmp_img_data;

	if (keycode == ESC)
	{
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
	if (keycode == 13) // forward (W)
		walk_forward(&info->player_info, info->map_info.map);
	else if (keycode == 1) // backward (S)
		walk_backward(&info->player_info, info->map_info.map);
	else if (keycode == 0) // left (A)
		walk_left(&info->player_info, info->map_info.map);
	else if (keycode == 2) // right (D)
		walk_right(&info->player_info, info->map_info.map);
	else if (keycode == 123) // turn left (<-)
		turn_left(&info->player_info);
	else if (keycode == 124) // turn right (->)
		turn_right(&info->player_info);
	if (keycode == 13 || (keycode >= 0 && keycode <= 2) || keycode == 123 || keycode == 124)
	{
		tmp_img_data = &info->mlx_info.img_data;
		render_next_image(&info->mlx_info, info);
		mlx_destroy_image(info->mlx_info.mlx, tmp_img_data->img);
	}
	return (0);
}
