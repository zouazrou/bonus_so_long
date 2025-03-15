/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouazrou <zouazrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:19:38 by zouazrou          #+#    #+#             */
/*   Updated: 2025/03/15 20:52:45 by zouazrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	check_path(char **grid, int l, int w)
{
	int	y;
	int	x;

	y = 0;
	while (y < l)
	{
		x = 0;
		while (x < w)
		{
			if (grid[y][x] == 'E' || grid[y][x] == 'C')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

void	destroy_images(void *mlx, void ***ptr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_destroy_image(mlx, (*ptr)[i]);
		++i;
	}
	free(*ptr);
}

void	destroy_all(t_game *map, int err)
{
	destroy_images(map->mlx, &map->player.img, map->player.nb_frm);
	destroy_images(map->mlx, &map->wall.img, map->wall.nb_frm);
	destroy_images(map->mlx, &map->enemy.img, map->enemy.nb_frm);
	destroy_images(map->mlx, &map->coll.img, map->coll.nb_frm);
	destroy_images(map->mlx, &map->exit.img, map->exit.nb_frm);
	destroy_images(map->mlx, &map->empty.img, map->empty.nb_frm);
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	if (map->mlx)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	if (map->grid)
		free_grid(&map->grid, map->length);
	if (err == PERROR)
		exit ((perror("Error "), EXIT_FAILURE));
	if (err == MAP)
		exit (EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	free_grid(char ***grid, int length)
{
	int	i;

	i = length;
	while (i >= 0)
		free((*grid)[i--]);
	free(*grid);
	*grid = NULL;
}
