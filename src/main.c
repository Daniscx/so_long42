/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 02:17:42 by dmaestro          #+#    #+#             */
/*   Updated: 2025/03/01 00:46:08 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_sprite	*ft_init_image(void);
static t_info	*ft_inicialitated(void);

int	main(int argc, char **argv)
{
	t_info	*gm;

	gm = NULL;
	gm = ft_inicialitated();
	if (argc != 2)
	{
		error_detected("check the  argumentes", gm);
		return (0);
	}
	mapping(gm, argv[1]);
	checkmapping(gm);
	if (gm->posible != 1)
		error_detected("the baby can't scape cheeater", gm);
	gm->mlx = mlx_init();
	if (!(gm->mlx))
		error_detected("fail when init mlx", gm);
	ft_image(gm);
	comprobation(gm);
	gm->wnw = mlx_new_window(gm->mlx, (gm->size_x - 1) * 32, (gm->size_y) * 32,
			"bebe toyota corolla");
	ft_createmap(gm);
	mlx_key_hook(gm->wnw, keycontroller, gm);
	mlx_hook(gm->wnw, X, 0, exit2, gm);
	mlx_loop(gm->mlx);
	return (1);
}

int	exit2(t_info *gm)
{
	finish_game(gm, 'L');
	return (1);
}

static t_sprite	*ft_init_image(void)
{
	t_sprite	*img;

	img = NULL;
	img = malloc(sizeof(t_sprite));
	img->exc0 = NULL;
	img->wall = NULL;
	img->backgroung = NULL;
	img->rings = NULL;
	img->ply_right = NULL;
	img->ply_left = NULL;
	img->ply_front = NULL;
	img->ply_back = NULL;
	img->exc1 = NULL;
	return (img);
}

static t_info	*ft_inicialitated(void)
{
	t_info	*gm;

	gm = NULL;
	gm = malloc(sizeof(t_info));
	gm->map = NULL;
	gm->size_x = 0;
	(gm->mlx) = NULL;
	gm->size_y = 0;
	gm->p_x = 0;
	gm->p_y = 0;
	gm->wnw = NULL;
	gm->sprite = ft_init_image();
	gm->e_y = 0;
	gm->e_x = 0;
	gm->posible = 0;
	return (gm);
}
