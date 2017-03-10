/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 23:31:09 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/08 23:31:10 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *str, char (*f)(unsigned int, char))
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
			new[i2] = f(i, str[i]);
			i2++;
			i++;
		}
		new[i2] = '\0';
		return (new);
	}
	return (NULL);
}
