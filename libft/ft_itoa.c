/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 21:50:19 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/09 19:07:26 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int		size;

	size = 0;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		size += 1;
	}
	size += 1;
	return (size);
}

char		*ft_itoa(int n)
{
	char	*new;
	int		size;
	int		cont;

	size = ft_size(n);
	cont = 0;
	if (n < 0)
		size += 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(new = (char *)malloc(sizeof(*new) * size + 1)))
		return (NULL);
	if (n < 0)
		cont = 1;
	if (n < 0)
		n *= -1;
	new[size] = '\0';
	while (size--)
	{
		new[size] = (n % 10) + '0';
		n = n / 10;
	}
	if (cont == 1)
		new[0] = '-';
	return (new);
}
