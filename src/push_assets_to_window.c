/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_assets_to_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:46:47 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/15 00:46:54 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_push_avatar_to_window(t_utils *ptr, int i, int j)
{
	(*ptr).avatar_pos_x = j;
	(*ptr).avatar_pos_y = i;
	mlx_put_image_to_window \
			((*ptr).mlx, (*ptr).win, (*ptr).avatar, j * (*ptr).xpm_size, \
			i * (*ptr).xpm_size);
}

void	ft_push_collectible_to_window(t_utils *ptr, int i, int j)
{
	mlx_put_image_to_window \
	((*ptr).mlx, (*ptr).win, (*ptr).collectible, j * (*ptr).xpm_size, \
	i * (*ptr).xpm_size);
}

void	ft_push_wall_to_window(t_utils *ptr, int i, int j)
{
	mlx_put_image_to_window \
			((*ptr).mlx, (*ptr).win, (*ptr).wall, j * (*ptr).xpm_size, \
			i * (*ptr).xpm_size);
}

void	ft_push_scene_to_window(t_utils *ptr, int i, int j)
{
	mlx_put_image_to_window \
			((*ptr).mlx, (*ptr).win, (*ptr).scene, j * (*ptr).xpm_size, \
			i * (*ptr).xpm_size);
}

int	ft_push_assets_to_window(t_utils *ptr, char **tab_map)
{
	int	i;
	int	j;

	i = -1;
	while (tab_map[++i])
	{
		j = -1;
		while (tab_map[i][++j])
		{
			if (tab_map[i][j] == '1')
				ft_push_wall_to_window(ptr, i, j);
			else if (tab_map[i][j] == '0')
				ft_push_scene_to_window(ptr, i, j);
			else if (tab_map[i][j] == 'P')
				ft_push_avatar_to_window(ptr, i, j);
			else if (tab_map[i][j] == 'C')
				ft_push_collectible_to_window(ptr, i, j);
			else if (tab_map[i][j] == 'E')
				mlx_put_image_to_window \
						((*ptr).mlx, (*ptr).win, (*ptr).exit, \
						j * (*ptr).xpm_size, i * (*ptr).xpm_size);
		}
	}
	return (0);
}
