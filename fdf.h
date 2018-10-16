/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:08:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/07/05 11:08:00 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

# define ESC 113
# define PI 3.14

typedef struct		s_cor
{
	int				x;
	int				y;
	int				z;
	float			xf;
	float			yf;
	struct s_cor	*next;
}					t_cor;

typedef struct		s_map
{
	int				dx;
	int				dy;
	int				x;
	int				y;
	int				len;
	int				max_x;
	int				max_y;
	int				mashtab;
	void			*mlx;
	void			*win;
}					t_map;

t_cor				*ft_read(int fd, int i, int j);
void				ft_xy_max(t_map *map, t_cor *coord);
int					deal_key(int k);
void				ft_map(t_map *map, t_cor *coord);

void				ft_lineh(t_cor *coord, t_map *map);
void				ft_verth(t_cor *coord, t_map *map);
//void				ft_vertim_x(t_cor *cor, int a);

void				ft_remake_coords(t_cor *cor, t_map *map);


#endif