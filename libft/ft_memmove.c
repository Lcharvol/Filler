/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:41:13 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/09 22:05:07 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *new1;
	char *new2;

	if (dest < src)
		return (ft_memcpy(dest, src, n));
	if (dest > src)
	{
		if (n == 0 || dest == src)
			return (dest);
		new1 = (char *)dest;
		new2 = (char *)src;
		while (n--)
			new1[n] = new2[n];
		return (new1);
	}
	return (dest);
}
