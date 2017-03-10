/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:14:47 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/23 16:15:52 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualisateur.h"

void		ft_calc_score(t_env *p)
{
	int		i;
	int		i2;

	i = 0;
	p->scorep1 = 0;
	p->scorep2 = 0;
	while (i < p->map_size_y)
	{
		i2 = 0;
		while (i2 < p->map_size_x)
		{
			if (p->map[i][i2] == 'X' || p->map[i][i2] == 'x')
				p->scorep1 += 1;
			if (p->map[i][i2] == 'O' || p->map[i][i2] == 'o')
				p->scorep2 += 1;
			i2++;
		}
		i++;
	}
}

void		ft_draw_score(t_env *p)
{
	char	*str;

	ft_calc_score(p);
	ft_modif_color(56, 60, 150, p);
	p->l = WIDTH / 3;
	p->h = 20;
	ft_draw_rectangle((WIDTH / 2) + 120, (HEIGHT / 3) + 40, p);
	ft_modif_color(60, 76, 232, p);
	p->l = ((WIDTH / 3) * (p->scorep1 / (p->map_size_x * p->map_size_y)));
	p->h = 20;
	ft_draw_rectangle((WIDTH / 2) + 120, (HEIGHT / 3) + 40, p);
	ft_modif_color(180, 132, 52, p);
	p->l = WIDTH / 3;
	p->h = 20;
	ft_draw_rectangle((WIDTH / 2) + 120, (HEIGHT / 2) + 170, p);
	ft_modif_color(211, 151, 53, p);
	p->l = ((WIDTH / 3) * (p->scorep2 / (p->map_size_x * p->map_size_y)));
	p->h = 20;
	ft_draw_rectangle((WIDTH / 2) + 120, (HEIGHT / 2) + 170, p);
}

void		ft_modif_color(int r, int v, int b, t_env *p)
{
	p->r = r;
	p->v = v;
	p->b = b;
}
