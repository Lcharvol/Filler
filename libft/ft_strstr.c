/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:46:57 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/11 17:26:28 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *meule, const char *aiguille)
{
	int		i;
	int		i2;
	int		len;
	char	*meule2;

	i2 = 0;
	i = 0;
	len = 0;
	meule2 = (char *)meule;
	while (aiguille[len])
		len++;
	if (len == 0)
		return (meule2);
	while (meule2[i])
	{
		while (meule2[i + i2] == aiguille[i2] && meule2[i + i2] &&
				aiguille[i2])
			i2++;
		if (i2 == len)
			return (meule2 + i);
		i++;
		i2 = 0;
	}
	return (0);
}
