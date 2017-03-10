/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 08:17:08 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/01 08:17:09 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	ft_go_contact1(t_map *map, t_piece *p)
{
	int i;
	int i2;
	int ret;

	i = map->map_size_y - 1;
	p->final_x = 0;
	p->final_y = 0;
	ret = 0;
	while (i > 0)
	{
		i2 = map->map_size_x - 1;
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

int	ft_go_contact2(t_map *map, t_piece *p)
{
	int i;
	int i2;
	int ret;

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

int	ft_big_map(t_map *map, t_piece *p)
{
	int ret;

	ft_get_contact(p, map);
	if (p->contact == 0)
	{
		if (map->my_pos_y < map->pos_enemy_y)
		{
			if (ft_go_contact1(map, p) == 1)
				return (1);
		}
		else if (map->my_pos_y >= map->pos_enemy_y)
		{
			if (ft_go_contact2(map, p) == 1)
				return (1);
		}
	}
	else
	{
		ret = ft_algo3(map, p);
		if (ret == 0)
			return (1);
	}
	return (0);
}

int	ft_small_map(t_map *map, t_piece *p)
{
	if (map->my_pos_y < (map->map_size_y / 2))
	{
		if (map->my_pos_x < (map->map_size_x / 2))
		{
			if (ft_algo2(map, p) == 1)
				return (1);
		}
		else if (map->my_pos_x >= (map->map_size_x / 2))
			if (ft_algo2_2(map, p) == 1)
				return (1);
	}
	else if (map->my_pos_y >= (map->map_size_y / 2))
	{
		if (map->my_pos_x < (map->map_size_x / 2))
		{
			if (ft_algo1(map, p) == 1)
				return (1);
		}
		else if (map->my_pos_x >= (map->map_size_x / 2))
			if (ft_algo1_2(map, p) == 1)
				return (1);
	}
	return (0);
}

int	ft_play(t_map *map, t_piece *p)
{
	if (map->map_size_y < 20)
		return (ft_small_map(map, p));
	if (map->map_size_y >= 20)
		return (ft_big_map(map, p));
	return (0);
}
