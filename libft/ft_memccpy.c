/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:04:18 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/07 21:42:02 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((char *)src)[i] == c)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
			return (dest + i);
		}
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (NULL);
}
