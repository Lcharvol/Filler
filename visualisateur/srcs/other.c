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

void		ft_draw_rectangle(int start_x, int start_y, t_env *p)
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

void		ft_draw_title(t_env *p)
{
	int		n;
	int		r;

	p->img2 = mlx_xpm_file_to_image(p->mlx, "fond.xpm", &n, &r);
	p->ret2 = mlx_get_data_addr(p->img, &(p->bits_per_pixel),
		&(p->size_line), &(p->endian));
}

void		ft_draw(t_env *p)
{
	ft_draw_background(p);
	ft_draw_menu(p);
	ft_draw_score(p);
	ft_draw_map(p);
}

int			ft_is_number(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

void		ft_print_final(t_env *p)
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
