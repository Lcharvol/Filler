/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 23:30:54 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/13 23:56:21 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *str, char (*f)(char))
{
	int		i;
	int		i2;
	char	*new;

	i = 0;
	i2 = 0;
	if (str != NULL && f != NULL)
	{
		while (str[i])
			i++;
		if (!(new = (char *)malloc(i * sizeof(*new) + 1)))
			return (NULL);
		i = 0;
		while (str[i])
		{
			new[i2] = f(str[i]);
			i2++;
			i++;
		}
		new[i2] = '\0';
		return (new);
	}
	return (NULL);
}
