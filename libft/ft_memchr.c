/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 21:06:03 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/10 23:37:56 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new;
	unsigned char	a;
	size_t			i;

	i = 0;
	a = (unsigned char)c;
	new = (unsigned char *)s;
	while (n != 0)
	{
		if (new[i] == a)
			return (new + i);
		i++;
		n--;
	}
	return (NULL);
}
