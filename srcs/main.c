/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 02:29:43 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/23 16:32:11 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		get_real_piece_size(t_piece *p)
{
	int		i;
	int		i2;

	i = -1;
	p->start_x = p->size_x;
	p->start_y = p->size_y;
	while (++i < p->size_y)
	{
		i2 = -1;
		while (++i2 < p->size_x)
			if (p->piece[i][i2] == '*')
			{
				if (i2 < p->start_x)
					p->start_x = i2;
				if (i2 > p->end_x)
					p->end_x = i2;
				if (i < p->start_y)
					p->start_y = i;
				if (i > p->end_y)
					p->end_y = i;
			}
	}
	p->real_size_x = (p->end_x - p->start_x) + 1;
	p->real_size_y = (p->end_y - p->start_y) + 1;
}

void		get_piece(t_piece *p)
{
	int		i;
	char	*line;

	i = 0;
	if (p->piece != NULL)
		free(p->piece);
	p->piece = (char **)malloc(sizeof(char *) * (p->size_y + 1));
	while (i < p->size_y)
	{
		ft_get_next_line(0, &line);
		p->piece[i] = (char *)malloc(sizeof(char *) * (p->size_x + 1));
		p->piece[i] = ft_strcpy(p->piece[i], (const char *)line);
		i++;
		ft_strdel(&line);
	}
	get_real_piece_size(p);
}

void		get_piece_size(char *line, t_piece *p)
{
	int		i;
	int		tmp;

	i = 0;
	p->size_x = 0;
	p->size_y = 0;
	while (line[i])
	{
		tmp = 0;
		while (is_number(line[i]) == 0 && line[i])
		{
			tmp += line[i] - 48;
			if (is_number(line[i + 1]) == 0)
				tmp *= 10;
			i++;
		}
		if (p->size_y == 0)
			p->size_y = tmp;
		else if (p->size_x == 0)
			p->size_x = tmp;
		i++;
	}
	ft_strdel(&line);
	get_piece(p);
}

void		init_struct(t_map *map, t_piece *p)
{
	map->map = NULL;
	map->player = 0;
	map->map_size_x = 0;
	map->map_size_y = 0;
	p->final_x = 0;
	p->final_y = 0;
	p->size_x = 0;
	p->size_y = 0;
	map->pos_enemy_x = 0;
	map->pos_enemy_y = 0;
	map->my_pos_x = 0;
	map->my_pos_y = 0;
	p->start_x = 0;
	p->end_x = 0;
	p->start_y = 0;
	p->end_y = 0;
	p->contact = 0;
}

int			main(void)
{
	t_map	*map;
	t_piece	*p;

	map = (t_map *)malloc(sizeof(*map));
	p = (t_piece *)malloc(sizeof(*p));
	init_struct(map, p);
	get_player(map);
	while (1)
	{
		get_the_ret(map, p);
		if (play(map, p) == 1)
		{
			if (last_try(map, p) == 1)
			{
				print_result(p, map);
				exit(1);
			}
		}
	}
	free(p->piece);
	free(map);
	free(p);
	return (0);
}
