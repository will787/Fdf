#include "../includes/fdf.h"

void bresenham_fill(double x, double y, double x1, double y2, mlx_image_t *image)
{
    double point_initial_x;
    double point_initial_y;
    int max;

    point_initial_x = x1 - x;
    point_initial_y = y2 - y;

    max = MAX1(MOD(point_initial_x), MOD(point_initial_y));
    point_initial_x /= max;
    point_initial_y /= max;

    while((int)(x - x1) || (int)(y - y2))
    {
        mlx_put_pixel(image, x, y, 0xffffff);
        x += point_initial_x;
        y += point_initial_y;

    }
}