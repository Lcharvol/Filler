/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:10:42 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/10 00:28:45 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *str, char c)
{
	int		words;
	int		i;
	int		in;

	in = 0;
	words = 0;
	i = 0;
	while (str[i])
	{
		if (in == 1 && str[i] == c)
		{
			in = 0;
		}
		if (in == 0 && str[i] != c)
		{
			in = 1;
			words++;
		}
		i++;
	}
	return (words);
}

static int	ft_countlen(const char *str, char c)
{
	int		len;

	len = 0;
	while (*str != '\0' && *str != c)
	{
		str++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		words;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	words = ft_countwords((const char *)s, c);
	if (!(new = (char **)malloc(sizeof(*new) * words + 1)))
		return (NULL);
	while (words--)
	{
		while (*s == c && *s != '\0')
			s++;
		new[i] = ft_strsub((const char *)s, 0, ft_countlen(s, c));
		if (new[i] == NULL)
			return (NULL);
		s = s + ft_countlen((char *)s, c);
		i++;
	}
	new[i] = NULL;
	return (new);
}
