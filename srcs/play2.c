/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:18:15 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/25 18:18:17 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_contact(t_piece *p, t_map *map)
{
	int	i;
	int	i2;

	i = 2;
	while (++i < map->map_size_y - 3)
	{
		i2 = 2;
		while (++i2 < map->map_size_x - 3)
		{
			if (map->map[i][i2] == map->me[0] || map->map[i][i2] == map->me[1])
				if (map->map[i][i2 + 3] == map->en[0] || map->map[i][i2 - 3]
					== map->en[0]
					|| map->map[i + 3][i2] == map->en[0] || map->map[i - 3][i2]
					== map->en[0]
					|| map->map[i][i2 + 3] == map->en[1] || map->map[i][i2 - 3]
					== map->en[1]
					|| map->map[i + 3][i2] == map->en[1] || map->map[i - 3][i2]
					== map->en[1])
				{
					p->contact = 1;
					return ;
				}
		}
	}
}

int		count_contact(t_map *map, t_piece *p, int y, int x)
{
	int	i;
	int	i2;
	int o;

	i = -1;
	p->nbr_contact = 0;
	while (++i < p->size_y)
	{
		i2 = -1;
		while (++i2 < p->size_x)
			if (p->piece[i][i2] == '*')
			{
				o = 0;
				while (++o < 4)
					if ((i2 + x + o) < map->map_size_x && (i2 + x - o) > 0 &&
						(i + y + o) < map->map_size_y && (i + y - o) > 0)
						if (map->map[i + y][i2 + x + o] == map->en[0] ||
							map->map[i + y][i2 + x - o] == map->en[0] ||
							map->map[i + y + o][i2 + x] == map->en[0] ||
							map->map[i + y - o][i2 + x] == map->en[0])
							p->nbr_contact += (4 - o);
			}
	}
	return (p->nbr_contact);
}

int		algo3(t_map *map, t_piece *p)
{
	int	i;
	int	i2;
	int	nbr_contact_tmp;
	int	nbr_contact;

	nbr_contact = -1;
	i = map->map_size_y - (p->size_y - p->end_y);
	p->tmp_x = 0;
	p->tmp_y = 0;
	while (--i >= 0)
	{
		i2 = map->map_size_x - (p->size_x - p->end_x);
		while (--i2 >= 0)
			if (is_placable(i, i2, map, p) == 0)
			{
				nbr_contact_tmp = count_contact(map, p, i, i2);
				if (nbr_contact_tmp > nbr_contact)
				{
					nbr_contact = nbr_contact_tmp;
					p->tmp_x = i2;
					p->tmp_y = i;
				}
			}
	}
	return (algo3_2(nbr_contact, p, map));
}

int		algo1(t_map *map, t_piece *p)
{
	int	i;
	int	i2;
	int	ret;

	i = -1;
	p->final_x = 0;
	p->final_y = 0;
	ret = 0;
	while (++i < map->map_size_y)
	{
		i2 = map->map_size_x;
		while (--i2 > 0)
		{
			ret = is_placable(i, i2, map, p);
			if (ret == 0)
			{
				print_result(p, map);
				return (0);
			}
		}
	}
	return (1);
}

int		algo1_2(t_map *map, t_piece *p)
{
	int	i;
	int	i2;
	int	ret;

	i = -1;
	p->final_x = 0;
	p->final_y = 0;
	ret = 0;
	while (++i < map->map_size_y)
	{
		i2 = -1;
		while (++i2 < map->map_size_x)
		{
			ret = is_placable(i, i2, map, p);
			if (ret == 0)
			{
				print_result(p, map);
				return (0);
			}
		}
	}
	return (1);
}
