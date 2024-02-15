#include "../includes/fdf.h"
#include "../libs/libft/get_next_line/get_next_line_bonus.c"

static mlx_image_t* image;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void *param)
{
    mlx_t* mlx = param;

    if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 50;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 50;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 50;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 50;
}

int32_t main(int argc, char *argv[])
{  

   if(argc != 2 || !argv)
        return (printf("Passe o mapa\n"));
    if(parse_and_validate(argv[1]) == -1)
        return(printf("mapa inválido\n"));

    printf("%s\n", argv[1]);
    return(printf("acabou\n"));
}

int parse_and_validate(char *map)
{
    mlx_t* mlx;

    if((read_map(map) == -1))
        return -1;
    printf("%s\n", map);
    if(!(mlx = mlx_init(WIDTH, HEIGHT, "fdf", true)))
    {
        puts(mlx_strerror(mlx_errno));
        return(EXIT_FAILURE);
    }
    if(!(image = mlx_new_image(mlx, 128, 128)))
    {
        mlx_close_window(mlx);
        puts(mlx_strerror(mlx_errno));
        return(EXIT_FAILURE);
    }
    if(mlx_image_to_window(mlx, image, 180, 180) == -1)
    {
        mlx_close_window(mlx);
        puts(mlx_strerror(mlx_errno));
        return(EXIT_FAILURE);
    }
    mlx_loop_hook(mlx, ft_randomize, mlx);
    mlx_loop_hook(mlx, ft_hook, mlx);
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return(1);
}