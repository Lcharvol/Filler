/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:33:11 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/10 16:53:45 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	void *new_list;

	while (*alst != NULL)
	{
		new_list = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = new_list;
	}
	*alst = NULL;
}
