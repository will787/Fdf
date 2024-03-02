#include "../includes/fdf.h"

double mod(float i)
{
    return(i < 0) ? -i : i;
}

void isometric_image(double *x, double *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void bresenham_fill(double x, double y, double x1, double y2, fdf *data)
{
    static bres_args args;

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
    args.point_x = x1 - x;
    args.point_y = y2 - y;
    
    // 3d image
    isometric_image(&x, &y, args.z);
    isometric_image(&x1, &y2, args.z1);

    // // //------------------------- = -----------------------
    args.max = MAX1(MOD(args.point_x), MOD(args.point_x));
    args.point_x /= args.max;
    args.point_y /= args.max;
    printf("value de x{%f}\n", args. point_x);
    printf("value de y{%f}\n", args. point_y);
    // program = fill_all_points(x, y, x1, y2);
    if((x - args.point_x) || (y - args.point_y))
    {   
        x++;
        y++;
        mlx_put_pixel(data->image, x, y, data->color);
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
            if(axis_y < data->y - 1)
                bresenham_fill(axis_x, axis_y, axis_x, axis_y + 1, data); // depois desenhamos no eixo y
            if(axis_x < data->x - 1)
                bresenham_fill(axis_x, axis_y, axis_x + 1, axis_y, data); // desenhamos no eixo x
            axis_x++;
        }
        axis_y++;
    }

}

int fill_all_points(double point_x, double point_y, double point_f_x, double point_f_y)
{
    if(((int)point_x - (int)point_f_x == 0) && ((int)point_y - (int)point_f_y == 0))
    {
        return 0;
        ft_printf("saiu");
    }
    ft_printf("entro");
    return 1;
}