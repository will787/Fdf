#include "../includes/fdf.h"
#include <math.h>

void isometric_image(double *x, double *y, int z)
{
    static int i = -1;
    i += 1;
    if(!z){
        printf("cagou em algum momento {%i}\n", i);
        return ;
    }
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void bresenham_fill(double x, double y, double x1, double y2, fdf *data)
{
    double point_initial_x;
    double point_initial_y;
    int max;
    int z;
    int z1;
    
    z = data->z_3d[(int)y][(int)x];
    z1 = data->z_3d[(int)y2][(int)x1];

    // idea : create new instruct management a axis em bresenham fills, for each points conected
    // todo [pendency]
    //--zooom--//
    x *= data->zoom;
    y *= data->zoom;
    x1 *= data->zoom;
    y2 *= data->zoom;

    // color points;
    data->color = (z || z1) ? GREEN : WHITE; // definindo as variaveis lá dentro do headerfile 
    point_initial_x = x1 - x;
    point_initial_y = y2 - y;
    
    // 3d image
    isometric_image(&x, &y, z);
    isometric_image(&x1, &y2, z1);
    // ------------------------- = -----------------------
    max = MAX1(MOD(point_initial_x), MOD(point_initial_y));
    point_initial_x /= max;
    point_initial_y /= max;

    while((int)(x - x1) || (int)(y - y2))
    {
        // printf("Valor das casas [%f]", x);
        // printf("Valor das casas [%f]", y);
        // printf("\n\n---------------------\n\n");
        mlx_put_pixel(data->image, x, y, data->color);
        x += point_initial_x;
        y += point_initial_y;

    }
}

void texture_line(fdf *data)
{
	int axis_y;
	int axis_x;

	axis_y = 0;
	while(axis_y < data->y - 1)
    {    
        axis_x = 0;
        while(axis_x < data->x - 1)
        {
            //printf("%3d", data->z_3d[axis_y][axis_x]);
            //bresenham_fill(axis_y, axis_x, data->x - 1, data->y -1, data);
            bresenham_fill(axis_x, axis_y, axis_x + 1, axis_y, data); // desenhamos no eixo x
            bresenham_fill(axis_x, axis_y, axis_x, axis_y + 1, data); // depois desenhamos no eixo y
            axis_x++;
        }
        // printf("\n");
        axis_y++;
    }
}