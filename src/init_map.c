#include "../includes/fdf.h"

int init_map(fdf *data)
{
    data->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
    if(!data->mlx)
        return -1;
    data->image = mlx_new_image(data->mlx, 600, 600);
    data->zoom = 20;
    if(!data->image)
        return -1;
    if(mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
    {
        mlx_close_window(data->mlx);
        puts(mlx_strerror(mlx_errno));
        return -1;
    }
    // mlx_loop_hook(data->mlx, ft_randomize, data);
    mlx_loop_hook(data->mlx, key_move, data);
    mlx_loop(data->mlx);
    mlx_terminate(data->mlx);
	return 1;
}

void ft_randomize(void* param)
{
	fdf *data;

	data = (fdf *)param;
}