/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:59:46 by wivieira          #+#    #+#             */
/*   Updated: 2023/11/30 13:59:46 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h> 
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct gnl_list
{
	char			*content;
	struct gnl_list	*next;
}					g_list;

char	*get_next_line(int fd);
char	*outside_line(g_list *list);
void	ft_createnode(g_list **list, int fd);
void	ft_add(g_list **list, char *buffer);
void	copy_line(g_list *list, char *str);
void	finallylist(g_list **list);
void	free_list(g_list *list);
int		new_line(g_list *list);
int		countnewline(g_list *list);
g_list	*ft_lstlastg(g_list *list);
#endif