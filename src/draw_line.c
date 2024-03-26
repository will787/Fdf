#include "../includes/fdf.h"

void draw_line(double x, double y, double x1, double y2, fdf *data)
{
    bres_args args;

    args.z = data->z_3d[(int)y][(int)x];
    args.z1 = data->z_3d[(int)y2][(int)x1];
	if((int)x >= WIDTH || (int)y >= HEIGHT ||  (int)x1 >= WIDTH || (int)y2 >= HEIGHT)
		return ;
    //--zooom--//
    x *= data->zoom;
    y *= data->zoom;
    y2 *= data->zoom;
    x1 *= data->zoom;
    data->color = (args.z || args.z1) ? RED : WHITE; // definindo as variaveis lá dentro do headerfile 
    args.pt_x = x1 - x;
    args.pt_y = y2 - y;

    args.max = MAX1(FABS_MOD(args.pt_x), FABS_MOD(args.pt_y));
    args.pt_x /= args.max;
    args.pt_y /= args.max;
    while(true)
    {   
		if(x != (args.pt_x - x))
            x += args.pt_x;
        if(y != (args.pt_y - y))
            y+= args.pt_y;
		if(x == x1 && y == y2)
			break;
        else
           mlx_put_pixel(data->image, x, y, data->color);

    }
	printf("chegou ao  fim\n");
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
                draw_line(axis_x, axis_y, axis_x + 1, axis_y, data); // desenhamos no eixo x
            if(axis_y < data->y - 1)
                draw_line(axis_x, axis_y, axis_x, axis_y + 1, data); // depois desenhamos no eixo y
            axis_x++;
        }
        axis_y++;
    }
}