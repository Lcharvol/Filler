/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:09:50 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/08 23:28:09 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;
	unsigned int	i2;

	i2 = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(new = (char *)malloc(len * sizeof(*new) + 1)))
		return (NULL);
	while (i < start)
		i++;
	while (i - start < len)
	{
		new[i2] = s[i];
		i++;
		i2++;
	}
	new[i2] = '\0';
	return (new);
}
