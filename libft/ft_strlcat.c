/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:01:26 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/09 17:42:16 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	i2;
	unsigned int	result;

	i = 0;
	i2 = 0;
	result = ft_strlen(dest) + ft_strlen((char *)src);
	while (dest[i] && i < size)
		i++;
	if ((size - i) == 0)
		return (i + ft_strlen((char *)src));
	while (i != (size - 1) && src[i2] != 0)
	{
		dest[i] = src[i2];
		i++;
		i2++;
	}
	dest[i] = 0;
	return (result);
}
