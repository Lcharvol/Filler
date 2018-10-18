/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:42:27 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/23 15:48:03 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualisateur.h"

void		draw_rectangle(int start_x, int start_y, t_env *p)
{
	int		i;
	int		i2;
	int		t;

	i2 = 0;
	t = 0;
	while (i2 < (p->h * 4))
	{
		i = 0;
		while (i < (p->l * 4))
		{
			p->ret[i + t + ((start_y * WIDTH * 4) + (start_x * 4))] = p->r;
			p->ret[i + t + 1 + ((start_y * WIDTH * 4) + (start_x * 4))] = p->v;
			p->ret[i + t + 2 + ((start_y * WIDTH * 4) + (start_x * 4))] = p->b;
			p->ret[i + t + 3 + ((start_y * WIDTH * 4) + (start_x * 4))] = 0;
			i += 4;
		}
		i2 += 4;
		t += (WIDTH * 4);
	}
}

int			is_aly_adj(t_env *p, int i, int i2)
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

void		draw(t_env *p)
{
	draw_background(p);
	draw_menu(p);
	draw_score(p);
	draw_map(p);
}

int			is_number(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

void		print_final(t_env *p)
{
	char	*str;

	str = ft_itoa(p->scorep1);
	mlx_string_put(p->mlx, p->win, (WIDTH / 2) + 120, (HEIGHT / 2) - 10,
		0x0e74c3c, str);
	str = ft_itoa(p->scorep2);
	mlx_string_put(p->mlx, p->win, (WIDTH / 2) + 120, (HEIGHT / 2) + 110,
		0x03498db, str);
	str = p->p2;
	mlx_string_put(p->mlx, p->win, (WIDTH / 2) + 120, (HEIGHT / 2) - 100,
		0x0e74c3c, str);
	str = p->p1;
	mlx_string_put(p->mlx, p->win, (WIDTH / 2) + 120, (HEIGHT / 2) + 210,
		0x03498db, str);
}
