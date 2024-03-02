/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:10:06 by wivieira          #+#    #+#             */
/*   Updated: 2024/02/23 18:10:52 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libs/libft/includes/libft.h"
#include "../libs/MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>


#ifndef WIDTH
# define WIDTH 600
#endif

#ifndef HEIGHT
#define HEIGHT 600
#endif

#define MAX1(a, b) ((a > b) ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

# define WHITE 0xFFFFFFFF
# define BLUE 0x0000FFFF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define PINK 0xFFFF00FF
# define YELLOW 0xFF00FFFF

typedef struct
{
	int	x;
	int	y;
	int	**z_3d;
	int color;
	int zoom;
	mlx_t *mlx;
	mlx_image_t *image;
}	fdf;

typedef struct
{
	double point_x;
    double point_y;
    int max;
    int z;
    int z1;
} bres_args;

int32_t	main(int argc, char *argv[]);
int		read_map(char *route_map, fdf *data);
int drop_height(char* route_map);
int drop_width(char *route_map);
void alloc_matrix(char *line, int *z_line3d);
int ft_split_values(char *line, char c);
void bresenham_fill(double x, double y, double x1, double y2, fdf *data);
void texture_line(fdf *data);
int    init_map(fdf *data);
void isometric_image(double *x, double *y, int z);
void key_move(void* param);
void ft_randomize(void* param);
void init_args(fdf* data);
int fill_all_points(double point_x, double point_y, double point_f_x, double point_f_y);
// int32_t main(void);
#endif 
