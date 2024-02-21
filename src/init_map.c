#include "../includes/fdf.h"

static mlx_image_t *image;

int init_map(fdf *data)
{
    data->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
    if(!data->mlx)
        return -1;
    image = mlx_new_image(data->mlx, 600, 600);
    bresenham_fill(10,10, 600, 300, image);
    if(!image)
        return -1;
    if(mlx_image_to_window(data->mlx, image, 180, 180) == -1)
    {
        mlx_close_window(data->mlx);
        puts(mlx_strerror(mlx_errno));
        return -1;
    }
    mlx_loop(data->mlx);
    mlx_terminate(data->mlx);
    return 1;
}

// void ft_hook(void* param, fdf* data)
// {
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(data->mlx);
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
// 		image->instances[0].y -= 50;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
// 		image->instances[0].y += 50;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
// 		image->instances[0].x -= 50;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
// 		image->instances[0].x += 50;
// }