/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42madrid.con    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 02:17:04 by dmaestro          #+#    #+#             */
/*   Updated: 2025/01/30 18:47:05 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_extracting(char *arg, t_info *gm)
{
	int	i;
	int	fd;

	fd = open(arg, O_RDONLY);
	i = 1;
	gm->map = ft_calloc(gm->size_y + 1, sizeof(char *));
	if (gm->map == NULL)
		error_detected("mapping error", gm);
	while ((gm->map[i - 1] = get_next_line(fd)) != NULL)
		i++;
	close(fd);
}
void	ft_sizegt(char *arg, t_info *gm)
{
	int		fd;
	char	*line;
	int		i;
	int		x;

	line = NULL;
	x = 0;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error_detected("il n'est pas fd", gm);
	while (((line = get_next_line(fd))) != NULL)
	{
		i = 0;
		while (line[i])
			i++;
		if (gm->size_x == 0)
			gm->size_x = i;
		x += i;
		gm->size_y++;
		free(line);
	}
	if (((x + 1) % gm->size_x) != 0)
		error_detected("Il n'est pas simetrick", gm);
}

t_sprite *ft_init_image()
{
	t_sprite * img;
	img = malloc(200*sizeof(t_sprite* ));
	img->exc0 = NULL ;
	img->wall = NULL;
	img->backgroung = NULL; 
	img->rings = NULL;
	img->ply_right = NULL; 
	img->ply_left = NULL;
	img->ply_front = NULL;
	img->ply_back = NULL;
	img->exc1 = NULL;
	return(img);

}
t_info	*ft_inicialitated()
{
	t_info   *gm;
	gm = malloc(sizeof(t_info *));
	gm->map = NULL;
	gm->size_x = 0;
	(gm->mlx) = NULL;
	gm->size_y = 0;
	gm->p_x = 0;
	gm->p_y = 0;
	gm->wnw = NULL;
	return (gm);
}
void	ft_image(t_info *gm, t_sprite *sprite)
{
	char	*path;
	int		weith;
	int		hight;
	
	weith = 32;
	hight = 32;
	if (!(gm->mlx))
		error_detected("xpm not inicialitated", gm);
	path = "./textures/front_player.xpm";
	
	sprite->ply_front = mlx_xpm_to_image(gm->mlx, &path, &weith, &hight);
	if(!(sprite))
		error_detected("fail to take image", gm);
	ft_printf("%p",gm->mlx);
	ft_printf("%p", gm->mlx);
	path = "./textures/back_player.xpm";
	sprite->ply_back = mlx_xpm_to_image(gm->mlx, &path, &weith, &hight);
	path = "./textures/left_player.xpm";
	sprite->ply_left = mlx_xpm_to_image(gm->mlx, &path, &weith, &hight);
	write(1, "hola\n", 5);
	path = "./textures/right_player.xpm";
	sprite->ply_right = mlx_xpm_to_image(gm->mlx, &path, &weith, &hight);
	path = "./textures/exit0.xpm";
	sprite->exc0 = mlx_xpm_to_image(gm->mlx, &path, &weith, &hight);
	path = "exit1.xpm";
	sprite->exc1 = mlx_xpm_to_image(gm->mlx, &path, &weith, &hight);
	path = "./textures/coins.xpm";
	sprite->rings = mlx_xpm_to_image(gm->mlx, &path, &weith, &hight);
	path = "./textures/coins.xpm";
	sprite->wall = mlx_xpm_to_image(gm->mlx, &path, &weith, &hight);
	path = "./textures/background.xpm";
	sprite->backgroung = mlx_xpm_to_image(gm->mlx, &path, &weith, &hight);
}

void	mapping(t_info *gm, char *arg)
{
	if (ft_strncmp(arg + ft_strlen(arg) - 4, ".ber", 4) != 0)
		error_detected("Le type pour le fd il n'est\n", gm);
	ft_sizegt(arg, gm);
	ft_extracting(arg, gm);
	if (gm->map == NULL)
		error_detected("mappicitation il n'est pas bian estructuré\nº", gm);
}
