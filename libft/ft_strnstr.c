/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:29:24 by lcharvol          #+#    #+#             */
/*   Updated: 2016/11/08 22:54:51 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strnstr(unsigned const char *meule, unsigned const
		char *aiguille, int n)
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
	while (meule2[i] && i <= n - len)
	{
		while (meule2[i + i2] == aiguille[i2] && meule2[i + i2] != '\0' &&
				aiguille[i2] != '\0' && i <= n)
			i2++;
		if (i2 == len)
			return (meule2 + i);
		i++;
		i2 = 0;
	}
	return (0);
}
