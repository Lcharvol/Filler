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

void		draw_square(int start_x, int start_y, int size, t_env *p)
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

void		draw_background(t_env *p)
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

void		draw_title(t_env *p)
{
	int		n;
	int		r;

	p->img2 = mlx_xpm_file_to_image(p->mlx, TITLE_IMAGE, &n, &r);
	p->ret2 = mlx_get_data_addr(p->img, &(p->bits_per_pixel),
		&(p->size_line), &(p->endian));
}

void		draw_map(t_env *p)
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
			if (p->map[i][i2] == '.' && is_aly_adj(p, i, i2) == 2)
				modif_color(50, 50, 50, p);
			else if (p->map[i][i2] == '.' && is_aly_adj(p, i, i2) == 1)
				modif_color(42, 42, 42, p);
			else if (p->map[i][i2] == '.')
				modif_color(55, 55, 55, p);
			else if (p->map[i][i2] == 'X' || p->map[i][i2] == 'x')
				modif_color(60, 76, 232, p);
			else if (p->map[i][i2] == 'O' || p->map[i][i2] == 'o')
				modif_color(211, 151, 53, p);
			draw_square((i2 * s) + (i2 * 2) + 2, (i * s) + (i * 2) +
				((600 - (p->map_size_y * s) - (p->map_size_y * 2)) / 2), s, p);
		}
	}
}

void		draw_menu(t_env *p)
{
	int		l;

	l = WIDTH;
	p->r = 35;
	p->v = 35;
	p->b = 35;
	draw_square(WIDTH / 2, 0, WIDTH / 2, p);
	p->r = 25;
	p->v = 25;
	p->b = 25;
	p->l = 20;
	p->h = HEIGHT;
	draw_rectangle(WIDTH / 2, 0, p);
	draw_rectangle(WIDTH - p->l, 0, p);
	p->l = WIDTH;
	p->h = 20;
	draw_rectangle(0, 0, p);
	draw_rectangle(0, HEIGHT - p->h, p);
	p->l = WIDTH / 2;
	p->h = HEIGHT;
	draw_rectangle(0, 0, p);
}
