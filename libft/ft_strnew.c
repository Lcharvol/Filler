/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:46:05 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/11 16:49:54 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!(new = (char *)malloc(size * sizeof(*new) + 1)))
		return (NULL);
	while (i <= size)
		new[i++] = '\0';
	return (new);
}
