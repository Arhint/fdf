#include "fdf.h"

int		deal_key(int k)
{
	if (k == ESC)
		exit(0);
	return (0);
}

void	ft_putdots(t_map *map, t_cor *coord)
{
	int		color;
	t_cor	*tmp;

	tmp = coord;
	color = 0xFFFFF;
	while (tmp)
	{
		mlx_pixel_put(map->mlx, map->win, tmp->x * map->mashtab,
						tmp->y * map->mashtab, color);
		tmp = tmp->next;
	}
}

void	ft_xy_max(t_map *map, t_cor *coord)
{
	t_cor	*tmp;

	tmp = coord;
	map->max_y = 0;
	map->max_x = 0;
	map->mashtab = 100;
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
//	ft_putdots(map, coord);
}
