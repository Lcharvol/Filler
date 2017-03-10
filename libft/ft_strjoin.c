/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:48:01 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/08 23:35:23 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len1;
	int		len2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	i = 0;
	if (!(new = (char *)malloc((len1 + len2) * sizeof(*new) + 1)))
		return (NULL);
	while (i < (len1 + len2))
	{
		while (i < len1)
		{
			new[i] = s1[i];
			i++;
		}
		new[i] = s2[i - len1];
		i++;
	}
	new[i] = '\0';
	return (new);
}
