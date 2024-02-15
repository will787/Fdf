/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:35:48 by wivieira          #+#    #+#             */
/*   Updated: 2023/10/27 17:54:10 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{	
	char	*pt;
	size_t	lenght;

	lenght = ft_strlen(s1) + ft_strlen(s2);
	pt = ft_calloc(lenght + 1, 1);
	if (!pt)
		return (NULL);
	ft_strlcpy(pt, s1, ft_strlen(s1) + 1);
	ft_strlcat(pt, s2, lenght + 1);
	pt[lenght] = '\0';
	return (pt);
}