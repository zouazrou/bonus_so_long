/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:13:01 by zouazrou          #+#    #+#             */
/*   Updated: 2025/03/15 21:03:40 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mlx_put_images(t_game *map, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->win, map->empty.img[0], x
		* SIZE, y * SIZE);
	if (is_wall(map, x, y))
		mlx_put_image_to_window(map->mlx, map->win, map->wall.img[0], x
			* SIZE, y * SIZE);
	else if (is_player(map, x, y))
		(mlx_put_image_to_window(map->mlx, map->win, map->player.img[0], x
				* SIZE, y * SIZE));
	else if (is_coll(map, x, y))
		mlx_put_image_to_window(map->mlx, map->win, map->coll.img[0], x
			* SIZE, y * SIZE);
	else if (is_exit(map, x, y))
		mlx_put_image_to_window(map->mlx, map->win, map->exit.img[0], x
			* SIZE, y * SIZE);
	else if (is_enemy(map, x, y))
		mlx_put_image_to_window(map->mlx, map->win, map->enemy.img[0], x
			* SIZE, y * SIZE);
}

void	display_game(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->length)
	{
		x = 0;
		while (x < map->width)
			mlx_put_images(map, x++, y);
		y++;
	}
	put_moves(map);
}

int	animation(t_game *param)
{
	static void	*ptr;

	if (ptr ==  param->player.img[0])
		ptr = param->player.img[1];
	else if (ptr == param->player.img[1])
		ptr = param->player.img[2];
	else if (ptr == param->player.img[2])
		ptr = param->player.img[3];
	else
		ptr = param->player.img[0];
	usleep(100000);
	mlx_put_image_to_window(param->mlx, param->win, ptr,
		param->player.coord.x * SIZE, param->player.coord.y * SIZE);
	return (0);
}

void	game(t_game *map)
{
	if (init_ptrs(map) == false)
		exit((destroy_all(map, PERROR), 1));
	display_game(map);
	mlx_hook(map->win, 17, 0, close_win, map);
	mlx_key_hook(map->win, keyboard, map);
	mlx_loop_hook(map->mlx, animation, map);
	mlx_loop(map->mlx);
	exit((destroy_all(map, PERROR), 1));
}
