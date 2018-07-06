/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssavchen <ssavchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:42:00 by ssavchen          #+#    #+#             */
/*   Updated: 2018/07/05 11:42:00 by ssavchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cor	*ft_dellast(t_cor *lst)
{
	t_cor	*tmp;

	tmp = lst;
	while (tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
	return (lst);
}

t_cor	*ft_create_tcor()
{
	t_cor	*cord;

	if (!(cord = (t_cor *)malloc(sizeof(t_cor))))
		return (0);
	cord->x = 0;
	cord->y = 0;
	cord->z = 0;
	cord->next = NULL;
	return (cord);
}

t_cor	*ft_read(int fd, int i, int j)
{
	char	**res;
	char	*s;
	t_cor	*coord;
	t_cor	*tmp;

	coord = ft_create_tcor();
	tmp = coord;
	while (get_next_line(fd, &s) > 0)
	{
		i = 0;
		res = ft_strsplit(s, ' ');
		while (res[i])
		{
			coord->x = i + 1;
			coord->y = j + 1;
			coord->z = ft_atoi(res[i]);
			coord->next = ft_create_tcor();
			coord = coord->next;
			i++;
		}
		j++;
	}
	ft_dellast(tmp);
	close(fd);
	return (tmp);
}