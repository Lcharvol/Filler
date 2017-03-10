/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 05:17:04 by lcharvol          #+#    #+#             */
/*   Updated: 2017/01/31 05:17:05 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			ft_get_player(t_map *map)
{
	char		*line;

	ft_get_next_line(0, &line);
	if (ft_strncmp(line, "$$$", 2) == 0 && map->player == 0)
	{
		if (ft_strstr(line, "p2"))
			map->player = 2;
		if (ft_strstr(line, "p1"))
			map->player = 1;
		ft_wich_player(map);
	}
	ft_strdel(&line);
}

void			ft_get_strat_pos(int i, t_map *map, char *str)
{
	int			i2;
	static int	i3;

	if (i3 == map->map_size_y)
		return ;
	i3 = 0;
	while (++i3 < (map->map_size_y))
	{
		i2 = 0;
		while (++i2 < (map->map_size_x))
		{
			if ((map->map[i3][i2] == map->en[0] ||
				map->map[i3][i2] == map->en[1]))
			{
				map->pos_enemy_x = i2;
				map->pos_enemy_y = i3;
			}
			if ((map->map[i3][i2] == map->me[0] ||
				map->map[i3][i2] == map->me[1]))
			{
				map->my_pos_x = i2;
				map->my_pos_y = i3;
			}
		}
	}
}

void			ft_get_map(t_map *map)
{
	int			i;
	char		*line;

	i = -1;
	ft_get_next_line(0, &line);
	ft_strdel(&line);
	map->map = (char **)malloc(sizeof(char *) * (map->map_size_y + 1));
	while (++i <= (map->map_size_y - 1))
	{
		ft_get_next_line(0, &line);
		map->map[i] = ft_strdup((const char *)(&line[4]));
		ft_strdel(&line);
	}
	ft_get_strat_pos(i, map, line);
}

void			ft_get_map_size(char *line, t_map *map)
{
	int			i;
	int			tmp;

	i = 0;
	map->map_size_x = 0;
	map->map_size_y = 0;
	while (line[i])
	{
		tmp = 0;
		while (ft_is_number(line[i]) == 0 && line[i])
		{
			tmp += line[i] - 48;
			if (ft_is_number(line[i + 1]) == 0)
				tmp *= 10;
			i++;
		}
		if (map->map_size_y == 0)
			map->map_size_y = tmp;
		else if (map->map_size_x == 0)
			map->map_size_x = tmp;
		i++;
	}
	ft_get_map(map);
}

int				ft_get_the_ret(t_map *map, t_piece *p)
{
	char		*line;

	p->piece = NULL;
	while (ft_get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			ft_get_map_size(line, map);
			ft_strdel(&line);
		}
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			ft_get_piece_size(line, p);
			return (1);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}
