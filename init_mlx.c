#include "cub3d.h"

void	initialize_mlx(t_mlx_info *mlx_info)
{
	mlx_info->mlx = mlx_init();
	mlx_info->win_width = 1000;
	mlx_info->win_height = 1000;
	mlx_info->mlx_win = mlx_new_window(mlx_info->mlx, mlx_info->win_width, mlx_info->win_width, "Hello World");
	mlx_info->img_data.img = mlx_new_image(mlx_info->mlx, mlx_info->win_width, mlx_info->win_height);
	mlx_info->img_data.addr = mlx_get_data_addr(mlx_info->img_data.img, &mlx_info->img_data.bits_per_pixel, &mlx_info->img_data.line_length, &mlx_info->img_data.endian);
}
