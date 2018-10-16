#include "fdf.h"

int		deal_key(int k)
{
	if (k == ESC)
		exit(0);
	return (0);
}


void	ft_xy_max(t_map *map, t_cor *coord)
{
	t_cor	*tmp;

	tmp = coord;
	map->max_y = 0;
	map->max_x = 0;
	while (tmp)
	{
		if (tmp->x > map->max_x)
			map->max_x = tmp->x;
		if (tmp->y > map->max_y)
			map->max_y = tmp->y;
		tmp = tmp->next;
	}
}

void	ft_map(t_map *map, t_cor *coord)
{
	t_cor	*tmp;

	tmp = coord;
	while (tmp->next)
	{
		if (tmp->x != map->max_x)
			ft_lineh(tmp, map);
		if (tmp->y != map->max_y)
			ft_verth(tmp, map);
		tmp = tmp->next;
	}
}


void	ft_remake_coords(t_cor *cor, t_map *map)
{
	t_cor	*tmp;

	tmp = cor;
	while (tmp)
	{
		tmp->x *= map->mashtab;
		tmp->y *= map->mashtab;
		tmp->z *= map->mashtab;
		tmp = tmp->next;
	}
	map->max_x *= map->mashtab;
	map->max_y *= map->mashtab;
}

//void	ft_vertim_x(t_cor *cor, int a)
//{
//	t_cor	*tmp;
//
//	tmp = cor;
//	while (tmp)
//	{
//		tmp->y = tmp->y * (cos(PI / 180 * a)) + tmp->z * (sin(PI / 180 * a));
//		tmp->z = -tmp->y * (sin(PI / 180 * a)) + tmp->z * (cos(PI / 180 * a));
//		tmp = tmp->next;
//	}
//}
