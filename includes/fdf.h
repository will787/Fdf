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
# define WIDTH 512
#endif

#ifndef HEIGHT
#define HEIGHT 512
#endif

typedef struct pointers_views{
	double	x;
	double	y;
	double	z;
}	t_pointers;

int32_t main(int argc, char* argv[]);
int parse_and_validate(char *map);
int read_map(char *route_map);
//int32_t main(void);
#endif 
