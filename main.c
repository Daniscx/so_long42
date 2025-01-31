/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42madrid.con    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 02:17:42 by dmaestro          #+#    #+#             */
/*   Updated: 2025/01/30 17:41:24 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int main(int argc, char **argv)
{
    t_info   *gm;
	t_sprite *sprite;
	int y;

	y = 0;
	sprite = ft_init_image();
		gm = ft_inicialitated();
	if ( argc != 2)
    {
        error_detected("Il n'est pas argumente", NULL);
        return(0);
    }	
	mapping(gm, argv[1]);
	checkmapping(gm);
	while(gm && gm->map[y])
	{
		ft_printf("%s", gm->map[y]);
		y++;
	}
	gm->mlx = mlx_init();
	if(!(gm->mlx))
		error_detected("fail when init mlx",gm);
	ft_image(gm, sprite);
	mlx_get_screen_size(gm->mlx, &gm->size_x, &gm->size_y);
	gm->wnw = mlx_new_window(gm->mlx, (gm->size_x), (gm->size_y), "prueba");
	ft_printf("%s", "hola");

	
    
}
