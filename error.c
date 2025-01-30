/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42madrid.con    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:09:28 by dmaestro          #+#    #+#             */
/*   Updated: 2025/01/06 18:39:37 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void free_double_pointer(char **map)
{
    int y;
    if(!map)
		return ;
    y = 0;
    while (map[y])
        y++;
    while (y > 0)
    {   
		free(map[y--]);
		y--;
	}
	free(map);
	exit(0);
}
void error_detected(const char *error, t_info *gm)
{
    ft_printf("%s", error);
    if(gm->map != NULL)
        free_double_pointer(gm->map);

    if(gm)
        free(gm);

}

