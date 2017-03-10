/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 10:13:08 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/23 15:44:28 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualisateur.h"

static int	ft_loop_key_hook(t_env *p)
{
	char	*str;

	if (p->pause == 0)
	{
		p->ret = mlx_get_data_addr(p->img, &(p->bits_per_pixel),
		&(p->size_line), &(p->endian));
		ft_read_output(p);
		ft_draw(p);
		mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
		mlx_put_image_to_window(p->mlx, p->win, p->img2, 0, 0);
		mlx_destroy_image(p->mlx, p->img);
		p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
		ft_print_final(p);
	}
	if (p->pause == 1)
	{
		str = "PAUSE";
		mlx_string_put(p->mlx, p->win, (WIDTH / 4) - 10, (HEIGHT / 2) - 10,
			0x0FFFFFF, str);
	}
	return (0);
}

int			ft_key_hook(int keycode, t_env *p)
{
	int		i;
	int		j;

	i = 1;
	if (keycode == ECHAP)
		exit(1);
	ft_loop_key_hook(p);
	return (0);
}

int			ft_mouse_hook(int button, int x, int y, t_env *p)
{
	if (button == 1)
	{
		if (p->pause == 0)
			p->pause = 1;
		else if (p->pause == 1)
			p->pause = 0;
	}
	ft_loop_key_hook(p);
	return (0);
}

void		ft_start_struct(t_env *p)
{
	p->pause = 0;
	p->r = 0;
	p->v = 0;
	p->b = 0;
	p->map = NULL;
	p->scorep1 = 0;
	p->scorep2 = 0;
	p->map_size_x = 0;
	p->map_size_y = 0;
}

int			main(void)
{
	t_env	*p;

	p = (t_env *)malloc(sizeof(t_env));
	ft_start_struct(p);
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "Filler_visualisateur");
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	ft_draw_title(p);
	mlx_hook(p->win, 2, 2, ft_key_hook, p);
	mlx_mouse_hook(p->win, ft_mouse_hook, p);
	ft_loop_key_hook(p);
	mlx_loop_hook(p->mlx, ft_loop_key_hook, p);
	free(p->map);
	mlx_loop(p->mlx);
	free(p);
	return (0);
}
