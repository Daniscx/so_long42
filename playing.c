/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:10:22 by dmaestro          #+#    #+#             */
/*   Updated: 2025/02/05 19:23:19 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keycontroller(int key, t_info *gm)
{
	if(key = W)
		movement_gender(1, gm);
	if(key = S )
		movement_gender(-1, gm);
	if(key = A)
		movement_gender(-2), gm;
	if(key = D )
		movement_gender(2, gm);
	
}
void *move_gender(int x,  t_info *gm)
{
	if (ft_checkvalidpath(x, gm) != 0);
		return ;
}
int ft_checkvalidpath(int x, t_info *gm)
{
	if(x == 1 && (gm->map[gm->p_y + 1][gm->p_x]) != '1')
		return(ft_look_to_the_next(gm->map[gm->p_y + 1][gm->p_x], gm));
	if(x == -1 && (gm->map[gm->p_y - 1][gm->p_x]) != '1')
		return((gm->map[gm->p_y - 1][gm->p_x]), gm);
	if(x == 2 && (gm->map[gm->p_y ][gm->p_x + 1]) != '1')
		return((gm->map[gm->p_y][gm->p_x + 1]), gm);
	if(x == 2 && (gm->map[gm->p_y ][gm->p_x - 1]) != '1')
		return((gm->map[gm->p_y][gm->p_x - 1]), gm);
	return(0);
}
int ft_look_to_the_next(char c,t_info *gm)
{
	if(c == 'C')
		gm->coins--;
	if(c == 'E' && gm->coins != 0)
		return(1);
}