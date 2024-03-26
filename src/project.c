// #include "../includes/fdf.h"

// static void rotate_x(int *x, int *y, int *z, double alpha)
// {
//     int old_y;

//     old_y = *y;
//     *y = old_y * cos(alpha) + *z * sin(alpha);
//     *z = -old_y * sin(alpha) + *z * sin(alpha);
// }

// static void rotate_z(int *x, int *y, int *z, double gamma)
// {
//     int old_x;
//     int old_y;

//     old_x = *x;
//     old_y = *y;

//     *x = old_x * cos(gamma) - old_y * sin(gamma);
//     *y = old_y * sin(gamma) + old_x * cos(gamma); 
// }