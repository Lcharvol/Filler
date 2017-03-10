/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:12:21 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/11 16:57:38 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	new = (*f)(lst);
	if (new && lst->next)
		new->next = ft_lstmap(lst->next, f);
	return (new);
}
