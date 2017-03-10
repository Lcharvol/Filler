/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 20:31:16 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/05 20:31:20 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualisateur.h"

void		ft_draw_square(int start_x, int start_y, int size, t_env *p)
{
	int		i;
	int		i2;
	int		tmp;

	i2 = 0;
	tmp = 0;
	while (i2 < (size * 4))
	{
		i = 0;
		while (i < (size * 4))
		{
			p->ret[i + tmp + ((start_y * WIDTH * 4) +
				(start_x * 4))] = p->r;
			p->ret[i + tmp + 1 + ((start_y * WIDTH * 4) +
				(start_x * 4))] = p->v;
			p->ret[i + tmp + 2 + ((start_y * WIDTH * 4) +
				(start_x * 4))] = p->b;
			p->ret[i + tmp + 3 + ((start_y * WIDTH * 4) +
				(start_x * 4))] = 0;
			i += 4;
		}
		i2 += 4;
		tmp += (WIDTH * 4);
	}
}

void		ft_draw_background(t_env *p)
{
	int		i;

	i = 0;
	while (i < (HEIGHT * WIDTH * 4))
	{
		(p->ret)[i] = 52;
		(p->ret)[i + 1] = 52;
		(p->ret)[i + 2] = 52;
		(p->ret)[i + 3] = 0;
		i += 4;
	}
}

int			ft_is_aly_adj(t_env *p, int i, int i2)
{
	if (i2 + 1 >= p->map_size_x || i2 - 1 < 0 || i + 1 >= p->map_size_y
		|| i - 1 < 0)
		return (0);
	if (p->map[i][i2 + 1] == 'X' || p->map[i][i2 - 1] == 'X' ||
		p->map[i][i2 + 1] == 'O' || p->map[i][i2 - 1] == 'O')
		return (1);
	if (p->map[i + 1][i2] == 'X' || p->map[i - 1][i2] == 'X' ||
		p->map[i + 1][i2] == 'O' || p->map[i - 1][i2] == 'O')
		return (1);
	if (i2 + 2 >= p->map_size_x || i2 - 2 < 0 || i + 2 >= p->map_size_y
		|| i - 2 < 0)
		return (0);
	if (p->map[i][i2 + 2] == 'X' || p->map[i][i2 - 2] == 'X' ||
		p->map[i][i2 + 2] == 'O' || p->map[i][i2 - 2] == 'O')
		return (2);
	if (p->map[i + 2][i2] == 'X' || p->map[i - 2][i2] == 'X' ||
		p->map[i + 2][i2] == 'O' || p->map[i - 2][i2] == 'O')
		return (2);
	return (0);
}

void		ft_draw_map(t_env *p)
{
	int		i;
	int		i2;
	int		s;

	s = ((WIDTH / 2) / (p->map_size_x)) - 2;
	i = -1;
	while (++i < p->map_size_y)
	{
		i2 = -1;
		while (++i2 < p->map_size_x)
		{
			if (p->map[i][i2] == '.' && ft_is_aly_adj(p, i, i2) == 2)
				ft_modif_color(50, 50, 50, p);
			else if (p->map[i][i2] == '.' && ft_is_aly_adj(p, i, i2) == 1)
				ft_modif_color(42, 42, 42, p);
			else if (p->map[i][i2] == '.')
				ft_modif_color(55, 55, 55, p);
			else if (p->map[i][i2] == 'X' || p->map[i][i2] == 'x')
				ft_modif_color(60, 76, 232, p);
			else if (p->map[i][i2] == 'O' || p->map[i][i2] == 'o')
				ft_modif_color(211, 151, 53, p);
			ft_draw_square((i2 * s) + (i2 * 2) + 2, (i * s) + (i * 2) +
				((600 - (p->map_size_y * s) - (p->map_size_y * 2)) / 2), s, p);
		}
	}
}

void		ft_draw_menu(t_env *p)
{
	int		l;

	l = WIDTH;
	p->r = 55;
	p->v = 55;
	p->b = 55;
	ft_draw_square(WIDTH / 2, 0, WIDTH / 2, p);
	p->r = 45;
	p->v = 45;
	p->b = 45;
	p->l = 20;
	p->h = HEIGHT;
	ft_draw_rectangle(WIDTH / 2, 0, p);
	ft_draw_rectangle(WIDTH - p->l, 0, p);
	p->l = WIDTH;
	p->h = 20;
	ft_draw_rectangle(0, 0, p);
	ft_draw_rectangle(0, HEIGHT - p->h, p);
	p->l = WIDTH / 2;
	p->h = HEIGHT;
	ft_draw_rectangle(0, 0, p);
}
