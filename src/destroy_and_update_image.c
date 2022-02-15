/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_update_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:46:03 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/15 00:46:07 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_fail_load_xpm_ressources_for_update_image(t_utils *ptr, char *str)
{
	mlx_destroy_image((*ptr).mlx, (*ptr).wall);
	mlx_destroy_image((*ptr).mlx, (*ptr).collectible);
	mlx_destroy_image((*ptr).mlx, (*ptr).exit);
	mlx_destroy_image((*ptr).mlx, (*ptr).scene);
	mlx_destroy_window((*ptr).mlx, (*ptr).win);
	mlx_destroy_display((*ptr).mlx);
	ft_free_struct_utils(ptr);
	printf("Failed to load xpm ressources or asset : %s.xpm\n", str);
	exit(0);
}

void	ft_destroy_and_update_image_aux(t_utils *ptr, char *str, void **asset)
{
	char	*str_joined;

	str_joined = ft_strjoin2((*ptr).xpm_path, str);
	*asset = mlx_xpm_file_to_image \
		((*ptr).mlx, str_joined, &(*ptr).pixel_x, &(*ptr).pixel_y);
	ft_free_struct_str(&str_joined);
	if (!(*asset))
		ft_fail_load_xpm_ressources_for_update_image(ptr, "avatar_right");
}

void	ft_destroy_and_update_image(t_utils *ptr, int key)
{
	mlx_destroy_image((*ptr).mlx, (*ptr).avatar);
	if (key == D || key == RIGHT)
		ft_destroy_and_update_image_aux(ptr, "/avatar_right.xpm", \
																&(*ptr).avatar);
	if (key == A || key == LEFT)
		ft_destroy_and_update_image_aux(ptr, "/avatar.xpm", &(*ptr).avatar);
	if (key == W || key == UP)
		ft_destroy_and_update_image_aux(ptr, "/avatar_right.xpm", \
																&(*ptr).avatar);
	if (key == S || key == DOWN)
		ft_destroy_and_update_image_aux(ptr, "/avatar.xpm", &(*ptr).avatar);
}
