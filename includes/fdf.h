/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:10:06 by wivieira          #+#    #+#             */
/*   Updated: 2024/02/23 17:21:46 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libs/libft/includes/libft.h"
#include "../libs/libft/includes/get_next_line_bonus.h"
#include "../libs/libft/includes/ft_printf.h"
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


typedef struct
{
	int	x;
	int	y;
	int	**z_3d;

	mlx_t *mlx;
	mlx_image_t *image;
}	fdf;

int32_t	main(int argc, char* argv[]);
int		read_map(char *route_map, fdf *data);
int drop_height(char* route_map);
int drop_width(char *route_map);
void alloc_matrix(char *line, int *z_line3d);
int ft_split_values(char *line, char c);
void bresenham_fill(double x, double y, double x1, double y2, void* image);
int    init_map(fdf *data);
// int32_t main(void);
#endif 
