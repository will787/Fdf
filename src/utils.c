#include "../includes/fdf.h"

int get_index(int x, int y, int width)
{
    return(y * width + x);
}

t_point new_point(int x, int y, fdf *data)
{
    t_point point;
    int index;

    index = get_index(x, y, data->width);
    point.x = x;
    point.y = y;
    point.z = data->z_3d[(int)y][(int)x];
    point.color = (point.z) ? RED : WHITE; // definindo as variaveis lá dentro do headerfile 
    return(point);
}