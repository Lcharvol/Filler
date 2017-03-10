/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 15:25:33 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/26 15:25:35 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_is_placable2(t_piece *p, int count, int i, int i2)
{
	if (count == 1)
	{
		p->final_x = i2;
		p->final_y = i;
		return (0);
	}
	return (1);
}

int		ft_algo3_2(int nbr_contact, t_piece *p, t_map *map)
{
	if (nbr_contact == -1)
		return (0);
	p->final_x = p->tmp_x;
	p->final_y = p->tmp_y;
	ft_print_result(p, map);
	return (1);
}

int		ft_algo2(t_map *map, t_piece *p)
{
	int	i;
	int	i2;
	int	ret;

	i = map->map_size_y;
	p->final_x = 0;
	p->final_y = 0;
	ret = 0;
	while (i > 0)
	{
		i2 = map->map_size_x;
		while (i2 > 0)
		{
			ret = ft_is_placable(i, i2, map, p);
			if (ret == 0)
			{
				ft_print_result(p, map);
				return (0);
			}
			i2--;
		}
		i--;
	}
	return (1);
}

int		ft_algo2_2(t_map *map, t_piece *p)
{
	int	i;
	int	i2;
	int	ret;

	i = map->map_size_y;
	p->final_x = 0;
	p->final_y = 0;
	ret = 0;
	while (i > 0)
	{
		i2 = -1;
		while (++i2 < map->map_size_x)
		{
			ret = ft_is_placable(i, i2, map, p);
			if (ret == 0)
			{
				ft_print_result(p, map);
				return (0);
			}
		}
		i--;
	}
	return (1);
}
