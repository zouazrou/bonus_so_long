/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:39:41 by zouazrou          #+#    #+#             */
/*   Updated: 2025/03/15 16:48:49 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	init_by_null(t_game *map, void ***ptr, int size)
{
	int	i;
// **arr
	i = 0;
	(*ptr) = malloc((size + 1) * sizeof(void *));
	if (!(*ptr))
		return (false);
	while (i < size + 1)
		(*ptr)[i++] = NULL;
	i = 0;
	while (i < size)
	{
		(*ptr)[i] = mlx_new_image(map->mlx, SIZE, SIZE);
		if ((*ptr)[i++] == NULL)
			return (false);
	}
	return (true);
}

bool	init_player(t_game *map)
{
	int	x;
	int	y;
	int size;

	size = 4;
	map->player.nb_frm = size;
	if (false == init_by_null(map, &map->player.img, size))
		return (false);
	map->player.img[0] = mlx_xpm_file_to_image(map->mlx, "./textures/player.xpm", &x, &y);
	map->player.img[1] = mlx_xpm_file_to_image(map->mlx, "./textures/player2.xpm", &x, &y);
	map->player.img[2] = mlx_xpm_file_to_image(map->mlx, "./textures/player3.xpm", &x, &y);
	map->player.img[3] = mlx_xpm_file_to_image(map->mlx, "./textures/player4.xpm", &x, &y);
	return (true);
}

bool	init_wall(t_game *map)
{
	int	x;
	int	y;
	int size;

	size = 1;
	map->wall.nb_frm = size;
	if (false == init_by_null(map, &map->wall.img, size))
		return (false);
	map->wall.img[0] = mlx_xpm_file_to_image(map->mlx, "./textures/wall.xpm", &x, &y);
	return (true);
}

bool	init_coll(t_game *map)
{
	int	x;
	int	y;
	int size;

	size = 1;
	map->coll.nb_frm = size;
	if (false == init_by_null(map, &map->coll.img, size))
		return (false);
	map->coll.img[0] = mlx_xpm_file_to_image(map->mlx, "./textures/coll.xpm", &x, &y);
	return (true);
}

bool	init_empty_sp(t_game *map)
{
	int	x;
	int	y;
	int size;

	size = 1;
	map->empty.nb_frm = size;
	if (false == init_by_null(map, &map->empty.img, size))
		return (false);
	map->empty.img[0] = mlx_xpm_file_to_image(map->mlx, "./textures/bg.xpm", &x, &y);
	return (true);
}

bool	init_enemy(t_game *map)
{
	int	x;
	int	y;
	int size;

	size = 1;
	map->enemy.nb_frm = size;
	if (false == init_by_null(map, &map->enemy.img, size))
		return (false);
	map->enemy.img[0] = mlx_xpm_file_to_image(map->mlx, "./textures/L_1.xpm", &x, &y);
	return (true);
}

bool	init_exit(t_game *map)
{
	int	x;
	int	y;
	int size;

	size = 1;
	map->exit.nb_frm = size;
	if (false == init_by_null(map, &map->exit.img, size))
		return (false);
	map->exit.img[0] = mlx_xpm_file_to_image(map->mlx, "./textures/exit.xpm", &x, &y);
	return (true);
}

bool	init_ptrs(t_game *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (false);
	map->win = mlx_new_window(map->mlx, map->width * SIZE, map->length * SIZE,
			"so_long");
	if (!map->win)
		return (false);

	// initualizi imgs
	if (init_player(map) && init_coll(map) && init_wall(map)
		&& init_enemy(map) && init_exit(map) && init_empty_sp(map))
		return (true);
	return (false);
}
