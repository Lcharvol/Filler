/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:08:35 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/07 17:28:32 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	int i;

	i = 0;
	if (str == NULL || f == NULL)
		return ;
	while (str != NULL && *str)
	{
		f(i, str++);
		i++;
	}
}
