/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 02:17:42 by dmaestro          #+#    #+#             */
/*   Updated: 2025/02/05 18:55:57 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int main(int argc, char **argv)
{
    t_info   *gm;
	int y;

	y = 0;
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
	ft_image(gm);
	gm->wnw = mlx_new_window(gm->mlx, (gm->size_x - 1)*32, (gm->size_y)*32, "prueba");
	ft_createmap(gm);
	mlx_key_hook(gm->wnw,key_user(),gm)

	

	
    
}
