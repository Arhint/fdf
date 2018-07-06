/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_put_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 15:16:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/07/05 15:16:00 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int a)
{
	return (a < 0 ? -a : a);
}

void	ft_draw1(t_map *map, t_cor *coord, int signx, int signy)
{
	int		d;

	map->x = coord->x * map->mashtab;
	map->y = coord->y * map->mashtab;
	d = -map->dx;
	map->len++;
	while (map->len--)
	{
		mlx_pixel_put(map->mlx, map->win, map->x, map->y, 0xFFFFF);
		map->x += signx;
		d += 2 * map->dy;
		if (d > 0)
		{
			d -= 2 * map->dx;
			map->y += signy;
		}
	}

}

void	ft_draw2(t_map *map, t_cor *coord, int signx, int signy)
{
	int		d;

	map->x = coord->x * map->mashtab;
	map->y = coord->y * map->mashtab;
	d = -map->dy;
	map->len++;
	while (map->len--)
	{
		mlx_pixel_put(map->mlx, map->win, map->x,
						map->y, 0xFFFFF);
		map->y += signy;
		d += 2 * map->dx;
		if (d > 0)
		{
			d -= 2 * map->dy;
			map->y += signx;
		}
	}

}

void	ft_lineh(t_cor *coord, t_map *map)
{
	t_cor	*tmp;
	int		signx;
	int		signy;

	tmp = coord->next;
	map->dx = ft_abs(coord->x * map->mashtab - tmp->x * map->mashtab);
	map->dy = ft_abs(coord->y * map->mashtab - tmp->y * map->mashtab);
	signx = coord->x < tmp->x ? 1 : -1;
	signy = coord->y < tmp->y ? 1 : -1;
	map->len = ft_maxint(map->dx, map->dy);
	if (map->dy <= map->dx)
		ft_draw1(map, coord, signx, signy);
	else
		ft_draw2(map, coord, signx, signy);
}

t_cor	*y_coord(t_cor *coord)
{
	t_cor	*tmp;

	tmp = coord;
	while(tmp)
	{
		if (tmp->y > coord->y && tmp->x == coord->x)
			return (tmp);
		tmp = tmp->next;
	}
	return(tmp);
}

void	ft_verth(t_cor *coord, t_map *map)
{
	t_cor	*tmp;
	int		signx;
	int		signy;

	tmp = y_coord(coord);
	map->dx = ft_abs(coord->x * map->mashtab - tmp->x * map->mashtab);
	map->dy = ft_abs(coord->y * map->mashtab - tmp->y * map->mashtab);
	signx = coord->x < tmp->x ? 1 : -1;
	signy = coord->y < tmp->y ? 1 : -1;
	map->len = ft_maxint(map->dx, map->dy);
	if (map->dy <= map->dx)
		ft_draw1(map, coord, signx, signy);
	else
		ft_draw2(map, coord, signx, signy);
}