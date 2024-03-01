#include "../includes/fdf.h"

void isometric_image(double *x, double *y, int z)
{
    *x = (*x - *y) * cos(1.2);
    *y = (*x + *y) * sin(1.2) - z;
}

void bresenham_fill(double x, double y, double x1, double y2, fdf *data)
{
    bres_args args;

    args.z = data->z_3d[(int)y][(int)x];
    args.z1 = data->z_3d[(int)y2][(int)x1];
    // idea : create new instruct management a axis em bresenham fills, for each points conected
    // todo [pendency]
    //--zooom--//
    x *= data->zoom;
    y *= data->zoom;
    x1 *= data->zoom;
    y2 *= data->zoom;

    // color points;
    data->color = (args.z || args.z1) ? RED : WHITE; // definindo as variaveis lá dentro do headerfile 
    args.point_initial_x = x1 - x;
    args.point_initial_y = y2 - y;
    
    // 3d image
    isometric_image(&x, &y, args.z);
    isometric_image(&x1, &y2, args.z1);

    // // //------------------------- = -----------------------
    args.max = MAX1(MOD(args.point_initial_x), MOD(args.point_initial_y));
    args.point_initial_x /= args.max;
    args.point_initial_y /= args.max;

    while((int)(x - x1) || (int)(y - y2))
    {
        mlx_put_pixel(data->image, x, y, data->color);
        x += args.point_initial_x;
        y += args.point_initial_y;
    }
	ft_printf("ate aqui funciona");
}

void texture_line(fdf *data)
{
	int axis_y;
	int axis_x;

	axis_y = 0;
	while(axis_y < data->y)
    {    
        axis_x = 0;
        while(axis_x < data->x)
        {
            //printf("%3d", data->z_3d[axis_y][axis_x]);
            //bresenham_fill(axis_y, axis_x, data->x - 1, data->y -1, data);
            if(axis_x < data->x - 1)
                bresenham_fill(axis_x, axis_y, axis_x + 1, axis_y, data); // desenhamos no eixo x
            if(axis_y < data->y - 1)
                bresenham_fill(axis_x, axis_y, axis_x, axis_y + 1, data); // depois desenhamos no eixo y
            axis_x++;
        }
        axis_y++;
    }

}