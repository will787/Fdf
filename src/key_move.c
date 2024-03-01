#include "../includes/fdf.h"

void key_move(void* param)
{
	fdf *data;

	data = (fdf *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->image->instances[0].y -= 50;
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->image->instances[0].y += 50;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->image->instances[0].x -= 50;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->image->instances[0].x += 50;
	texture_line(data);
}