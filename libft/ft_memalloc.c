/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:09:16 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/11 16:45:26 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*new;

	if (!(new = (char *)malloc(sizeof(*new) * size)))
		return (NULL);
	ft_memset(new, 0, size);
	return (new);
}
