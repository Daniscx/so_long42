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
	int y;

	y = 0;
  	gm = malloc(sizeof(t_info *));	
	if ( argc != 2)
    {
        error_detected("Il n'est pas argumente", gm);
        return(0);
    }
	mapping(gm, argv[1]);
	checkmapping(gm);
	while(gm && gm->map[y])
	{
		ft_printf("%s", gm->map[y]);
		y++;
	}
	if(!(gm->mlx))
		error_detected("fail when init mlx",gm);
	gm->wnw = mlx_new_window(gm->mlx, (gm->size_x*320), (gm->size_y)*320, "prueba");
	
    
}
