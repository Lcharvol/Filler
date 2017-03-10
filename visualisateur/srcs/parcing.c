/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 20:31:03 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/05 20:31:04 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualisateur.h"

void		ft_get_player_name(char *line, t_env *p)
{
	int i;

	i = 22;
	if (line[9] == 'p' && line[10] == '1')
	{
		while (line[i])
		{
			if (line[i] == '.')
				break ;
			i++;
		}
		p->p1 = ft_strsub((const char *)line, 23, i - 23);
	}
	if (line[9] == 'p' && line[10] == '2')
	{
		while (line[i])
		{
			if (line[i] == '.')
				break ;
			i++;
		}
		p->p2 = ft_strsub((const char *)line, 23, i - 23);
	}
	ft_strdel(&line);
}

void		ft_get_map2(t_env *p)
{
	int		i;
	char	*line;

	i = -1;
	ft_get_next_line(0, &line);
	ft_strdel(&line);
	p->map = (char **)malloc(sizeof(char *) * (p->map_size_y + 1));
	while (++i <= (p->map_size_y - 1))
	{
		ft_get_next_line(0, &line);
		p->map[i] = ft_strdup((const char *)(&line[4]));
		ft_strdel(&line);
	}
}

void		ft_get_map_size2(char *line, t_env *p)
{
	int i;
	int tmp;

	i = 0;
	p->map_size_x = 0;
	p->map_size_y = 0;
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
		if (p->map_size_y == 0)
			p->map_size_y = tmp;
		else if (p->map_size_x == 0)
			p->map_size_x = tmp;
		i++;
	}
	ft_strdel(&line);
	ft_get_map2(p);
}

void		ft_read_output(t_env *p)
{
	char	*line;
	int		i;

	i = 0;
	while (ft_get_next_line(0, &line) == 1)
	{
		if (ft_strncmp(line, "$$$", 2) == 0)
		{
			ft_get_player_name(line, p);
		}
		if (ft_strncmp(line, "Plateau", 6) == 0)
			ft_get_map_size2(line, p);
		if (ft_strncmp(line, "Piece", 4) == 0)
		{
			ft_strdel(&line);
			return ;
		}
	}
}
