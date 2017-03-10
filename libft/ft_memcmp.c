/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:57:48 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/10 00:27:14 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	unsigned char		*new1;
	unsigned char		*new2;

	i = 0;
	new1 = (unsigned char*)s1;
	new2 = (unsigned char*)s2;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (n--)
	{
		if (new1[i] != new2[i])
			return (new1[i] - new2[i]);
		i++;
	}
	return (0);
}
