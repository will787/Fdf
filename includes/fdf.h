/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:10:06 by wivieira          #+#    #+#             */
/*   Updated: 2024/02/08 14:13:36 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../libs/libft/includes/libft.h"
#include "../libs/libft/includes/get_next_line_bonus.h"
#include "../libs/libft/includes/ft_printf.h"
#include "../libs/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <math.h>
#include <stdlib.h>
#include <stdbool.h>


#ifndef WIDTH
# define WIDTH 800
#endif

#ifndef HEIGHT
#define HEIGHT 600
#endif

typedef struct pointers_views{
	int	x;
	int	y;
	int	**z_3d;
}			fdf;

int32_t	main(int argc, char* argv[]);
int		read_map(char *route_map, fdf *data);
int drop_height(char* route_map);
int drop_width(char *route_map);
void clear_matrix(char *line, int *z_line);
int ft_split_values_convert(char **line);
//int32_t main(void);
#endif 
