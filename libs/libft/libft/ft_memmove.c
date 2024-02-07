/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wivieira <wivieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:44:27 by wivieira          #+#    #+#             */
/*   Updated: 2023/10/25 17:31:27 by wivieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*sorc;

	dst = (unsigned char *) dest;
	sorc = (const unsigned char *) src;
	if (dst > sorc)
	{
		while (n--)
		{
			dst[n] = sorc[n];
		}
	}
	else
	{
		ft_memcpy (dst, src, n);
	}
	return (dest);
}
