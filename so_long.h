/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaestro <dmaestro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:07:59 by dmaestro          #+#    #+#             */
/*   Updated: 2025/02/22 20:16:59 by dmaestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "minilibx/mlx.h"

# define WALL = 1
# define COINS = C
# define PLAYER = P
# define EXIT = E
# define BACK_ROUND = 0

# define ESC 0xFF1B
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_sprite

{
	void		*ply_front;
	void		*ply_left;
	void		*ply_right;
	void		*ply_back;
	void		*backgroung;
	void		*exc0;
	void		*exc1;
	void		*rings;
	void		*wall;

}				t_sprite;

typedef struct s_info
{
	char		**map;
	void		*mlx;
	int			size_y;
	int			size_x;
	int			p_y;
	int			p_x;
	void		*wnw;
	int			coins;
	int			e_x;
	int			e_y;
	t_sprite	*sprite;

}				t_info;

void			mapping(t_info *gm, char *arg);
int				main(int argc, char **argv);
void			ft_extracting(char *arg, t_info *gm);
void			error_detected(const char *error, t_info *gm);
void			checkmapping(t_info *gm);
void			ft_image(t_info *gm);
t_info			*ft_inicialitated(void);
void			ft_createmap(t_info *gm);
void			ft_putintowindos(t_info *gm, char c, int x, int y);
int				keycontroller(int key, t_info *gm);
void	free_double_pointer(char **map);
void	get_the_original(t_info *gm, char c);

#endif
