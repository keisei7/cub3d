#include "cub3d.h"

bool	is_not_wall(t_player_info *player_info, char **map, double one_step, int step_direction)
{
	double	pos_x;
	double	pos_y;
	size_t	map_x;
	size_t	map_y;

	pos_x = player_info->pos_x;
	pos_y = player_info->pos_y;
	if (step_direction == X)
		pos_x += one_step + (one_step * 3);
	else // step_direction == Y
		pos_y += one_step + (one_step * 3);
	map_x = (size_t)pos_x;
	map_y = (size_t)pos_y;
	return (map[map_y][map_x] != '1');
}

void	walk_forward(t_player_info *player_info, char **map)
{
	if (player_info->dir_x == 0 && player_info->dir_y == -1) // North
	{
		if (is_not_wall(player_info, map, -0.1, Y))
			player_info->pos_y += -0.1;
	}
	else if (player_info->dir_x == 0 && player_info->dir_y == 1) // South
	{
		if (is_not_wall(player_info, map, 0.1, Y))
			player_info->pos_y += 0.1;
	}
	else if (player_info->dir_x == -1 && player_info->dir_y == 0) // West
	{
		if (is_not_wall(player_info, map, -0.1, X))
			player_info->pos_x += -0.1;
	}
	else // (player_info->dir_x == 1 && player_info->dir_y == 0) // East
	{
		if (is_not_wall(player_info, map, 0.1, X))
			player_info->pos_x += 0.1;
	}
}

void	walk_backward(t_player_info *player_info, char **map)
{
	if (player_info->dir_x == 0 && player_info->dir_y == -1) // North
	{
		if (is_not_wall(player_info, map, 0.1, Y))
			player_info->pos_y += 0.1;
	}
	else if (player_info->dir_x == 0 && player_info->dir_y == 1) // South
	{
		if (is_not_wall(player_info, map, -0.1, Y))
			player_info->pos_y += -0.1;
	}
	else if (player_info->dir_x == -1 && player_info->dir_y == 0) // West
	{
		if (is_not_wall(player_info, map, 0.1, X))
			player_info->pos_x += 0.1;
	}
	else // (player_info->dir_x == 1 && player_info->dir_y == 0) // East
	{
		if (is_not_wall(player_info, map, -0.1, X))
			player_info->pos_x += -0.1;
	}
}

void	walk_left(t_player_info *player_info, char **map)
{
	if (player_info->dir_x == 0 && player_info->dir_y == -1) // North
	{
		if (is_not_wall(player_info, map, -0.1, X))
			player_info->pos_x += -0.1;
	}
	else if (player_info->dir_x == 0 && player_info->dir_y == 1) // South
	{
		if (is_not_wall(player_info, map, 0.1, X))
			player_info->pos_x += 0.1;
	}
	else if (player_info->dir_x == -1 && player_info->dir_y == 0) // West
	{
		if (is_not_wall(player_info, map, 0.1, Y))
			player_info->pos_y += 0.1;
	}
	else // (player_info->dir_x == 1 && player_info->dir_y == 0) // East
	{
		if (is_not_wall(player_info, map, -0.1, Y))
			player_info->pos_y += -0.1;
	}
}

void	walk_right(t_player_info *player_info, char **map)
{
	if (player_info->dir_x == 0 && player_info->dir_y == -1) // North
	{
		if (is_not_wall(player_info, map, 0.1, X))
			player_info->pos_x += 0.1;
	}
	else if (player_info->dir_x == 0 && player_info->dir_y == 1) // South
	{
		if (is_not_wall(player_info, map, -0.1, X))
			player_info->pos_x += -0.1;
	}
	else if (player_info->dir_x == -1 && player_info->dir_y == 0) // West
	{
		if (is_not_wall(player_info, map, -0.1, Y))
			player_info->pos_y += -0.1;
	}
	else // (player_info->dir_x == 1 && player_info->dir_y == 0) // East
	{
		if (is_not_wall(player_info, map, 0.1, Y))
			player_info->pos_y += 0.1;
	}
}

void	turn_left(t_player_info *player_info)
{
	if (player_info->dir_x == 0) // North or South
	{
		player_info->plane_x = 0;
		if (player_info->dir_y == -1) // North
			player_info->plane_y = -0.66;
		else // South
			player_info->plane_y = 0.66;
		player_info->dir_x = player_info->dir_y;
		player_info->dir_y = 0;
	}
	else if (player_info->dir_y == 0) // West or East
	{
		if (player_info->dir_x == -1) // West
			player_info->plane_x = -0.66;
		else // East
			player_info->plane_x = 0.66;
		player_info->plane_y = 0;
		player_info->dir_y = player_info->dir_x * -1;
		player_info->dir_x = 0;
	}
}

void	turn_right(t_player_info *player_info)
{
	if (player_info->dir_x == 0) // North or South
	{
		player_info->plane_x = 0;
		if (player_info->dir_y == -1) // North
			player_info->plane_y = 0.66;
		else // South
			player_info->plane_y = -0.66;
		player_info->dir_x = player_info->dir_y * -1;
		player_info->dir_y = 0;
	}
	else if (player_info->dir_y == 0) // West or East
	{
		if (player_info->dir_x == -1) // West
			player_info->plane_x = 0.66;
		else // East
			player_info->plane_x = -0.66;
		player_info->plane_y = 0;
		player_info->dir_y = player_info->dir_x;
		player_info->dir_x = 0;
	}
}
