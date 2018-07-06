#include "fdf.h"

void	ft_printlist(t_cor *lst)
{
	int 	i;

	i = 1;
	while (lst)
	{
		ft_printf("row %.3d - x=%2d y=%3d z=%d\n", i, lst->x, lst->y, lst->z);
		lst = lst->next;
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	t_cor	*coord;
	t_map	map;

	if (argc != 2)
	{
		ft_printf("%s\n", "usage: ./fdf source_file");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error();
	coord = ft_read(fd, 0 ,0);
	ft_xy_max(&map, coord);
	while (map.mashtab * map.max_x > 1350 || map.mashtab * map.max_y > 900)
		map.mashtab--;
//	ft_printf("mashtab=%d max_x=%d max_y=%d\n", map.mashtab, map.max_x, map.max_y);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.max_x * map.mashtab + 100,
								 map.max_y * map.mashtab + 100, "FDF");
//	ft_recoords(&map, coord);
	ft_map(&map, coord);
	mlx_key_hook(map.win, deal_key, (void *)0);
	mlx_hook(map.win, 2, 5, deal_key, &map);
	mlx_loop(map.mlx);
//	ft_printlist(coord);
//	system("leaks fdf");
	return 0;
}