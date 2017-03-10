/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 06:28:13 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/01 06:28:14 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		ft_is_number(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

void	ft_wich_player(t_map *map)
{
	if (map->player == 1)
	{
		map->en = "Xx";
		map->me = "Oo";
	}
	if (map->player == 2)
	{
		map->en = "Oo";
		map->me = "Xx";
	}
}

int		ft_is_placable(int i, int i2, t_map *map, t_piece *p)
{
	int j;
	int j2;
	int count;

	j = -1;
	count = 0;
	if (i + p->size_y > map->map_size_y || i2 + p->size_x > map->map_size_x)
		return (1);
	while (++j <= (p->size_y - 1))
	{
		j2 = -1;
		while (++j2 <= (p->size_x - 1))
		{
			if (p->piece[j][j2] == '*' && (map->map[i + j][i2 + j2] ==
				map->en[0] || map->map[i + j][i2 + j2] ==
				map->en[0] - 32))
				return (1);
			if (p->piece[j][j2] == '*' && (map->map[i + j][i2 + j2] ==
				map->me[0] || map->map[i + j][i2 + j2] == map->me[0] - 32))
				count++;
		}
	}
	if (ft_is_placable2(p, count, i, i2) == 0)
		return (0);
	return (1);
}

void	ft_print_result(t_piece *p, t_map *map)
{
	ft_putnbr(p->final_y);
	ft_putchar(' ');
	ft_putnbr(p->final_x);
	ft_putchar('\n');
	map->my_pos_x = p->final_x;
	map->my_pos_y = p->final_y;
}

int		ft_last_try(t_map *map, t_piece *p)
{
	int	i;
	int	i2;
	int	ret;

	i = -1;
	p->final_x = 0;
	p->final_y = 0;
	ret = 0;
	while (++i < map->map_size_y - 1)
	{
		i2 = -1;
		while (++i2 < map->map_size_x - 1)
		{
			ret = ft_is_placable(i, i2, map, p);
			if (ret == 0)
			{
				ft_print_result(p, map);
				return (0);
			}
		}
	}
	return (1);
}
