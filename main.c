/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 02:17:42 by dmaestro          #+#    #+#             */
/*   Updated: 2025/02/19 18:27:34 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_info	*gm;
	int		y;

	y = 0;
	gm = NULL;
	gm = ft_inicialitated();
	if (argc != 2)
	{
		error_detected("Il n'est pas argumente", gm);
		return (0);
	}
	mapping(gm, argv[1]);
	if (gm->sprite == NULL)
		return (0);
	checkmapping(gm);
	if (gm->sprite == NULL)
		return (0);
	gm->mlx = mlx_init();
	if (!(gm->mlx))
		error_detected("fail when init mlx", gm);
	ft_image(gm);
	gm->wnw = mlx_new_window(gm->mlx, (gm->size_x - 1) * 32, (gm->size_y) * 32,
			"bebe toyota corolla");
	ft_createmap(gm);
	mlx_key_hook(gm->wnw, keycontroller, gm);
	mlx_loop(gm->mlx);
}
