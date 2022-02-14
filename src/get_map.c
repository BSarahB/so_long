/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:44:49 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/10 20:44:53 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_push_avatar_to_window(t_utils *ptr, int i, int j)
{
	(*ptr).avatar_pos_x = j;
	(*ptr).avatar_pos_y = i;
	mlx_put_image_to_window \
			((*ptr).mlx, (*ptr).win, (*ptr).avatar, j * (*ptr).xpm_size, i * (*ptr).xpm_size);
}

void	ft_push_collectible_to_window(t_utils *ptr, int i, int j)
{
	mlx_put_image_to_window \
	((*ptr).mlx, (*ptr).win, (*ptr).collectible, j * (*ptr).xpm_size, i * (*ptr).xpm_size);
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
				mlx_put_image_to_window \
						((*ptr).mlx, (*ptr).win, (*ptr).wall, j * (*ptr).xpm_size, i * (*ptr).xpm_size);
			else if (tab_map[i][j] == '0')
				mlx_put_image_to_window \
						((*ptr).mlx, (*ptr).win, (*ptr).scene, j * (*ptr).xpm_size, i * (*ptr).xpm_size);
			else if (tab_map[i][j] == 'P')
				ft_push_avatar_to_window(ptr, i, j);
			else if (tab_map[i][j] == 'C')
				ft_push_collectible_to_window(ptr, i, j);
			else if (tab_map[i][j] == 'E')
				mlx_put_image_to_window \
						((*ptr).mlx, (*ptr).win, (*ptr).exit, j * (*ptr).xpm_size, i * (*ptr).xpm_size);
		}
	}
	return (0);
}

void	*ft_get_images_id_aux(t_utils *ptr, char *str, void **asset)
{
	char	*str_joined;

	str_joined =  ft_strjoin2((*ptr).xpm_path, str);
	*asset = mlx_xpm_file_to_image \
			((*ptr).mlx, str_joined, &(*ptr).pixel_x, &(*ptr).pixel_y);
	ft_free_struct_str(&str_joined);
	return (*asset);

}

int	ft_fail_load_xpm_ressources(t_utils *ptr, char *str)
{
	if (*str == 'e' )
		mlx_destroy_image((*ptr).mlx, (*ptr).avatar);
	else if (*str == 'c')
	{
		mlx_destroy_image((*ptr).mlx, (*ptr).avatar);
		mlx_destroy_image((*ptr).mlx, (*ptr).exit);
	}
	else if (*str == 's')
	{
		mlx_destroy_image((*ptr).mlx, (*ptr).avatar);
		mlx_destroy_image((*ptr).mlx, (*ptr).exit);
		mlx_destroy_image((*ptr).mlx, (*ptr).collectible);
	}
	else if (*str == 'w')
	{
		mlx_destroy_image((*ptr).mlx, (*ptr).avatar);
		mlx_destroy_image((*ptr).mlx, (*ptr).exit);
		mlx_destroy_image((*ptr).mlx, (*ptr).collectible);
		mlx_destroy_image((*ptr).mlx, (*ptr).scene);
	}
	mlx_destroy_window((*ptr).mlx, (*ptr).win);
	mlx_destroy_display((*ptr).mlx);
	ft_free_struct_utils(ptr);
	printf("Failed to load xpm ressources or asset : %s.xpm\n", str);
	exit (0);
}

void	ft_get_images_id(t_utils *ptr)
{
	void	*asset;

	asset = ft_get_images_id_aux(ptr, "/avatar.xpm", &(*ptr).avatar);
	if (!asset)
		ft_fail_load_xpm_ressources(ptr, "avatar");
	asset = ft_get_images_id_aux(ptr, "/exit.xpm", &(*ptr).exit);
	if (!asset)
		ft_fail_load_xpm_ressources(ptr, "exit");
	asset = ft_get_images_id_aux(ptr, "/npxfess.xpm", &(*ptr).collectible);
	if (!asset)
		ft_fail_load_xpm_ressources(ptr, "collectible");
	asset = ft_get_images_id_aux(ptr, "/scene.xpm", &(*ptr).scene);
	if (!asset)
		ft_fail_load_xpm_ressources(ptr, "scene");
	asset = ft_get_images_id_aux(ptr, "/wall.xpm", &(*ptr).wall);
	if (!asset)
		ft_fail_load_xpm_ressources(ptr, "wall");
}

void	get_map(int fd, t_utils *ptr)
{
	char	*ans;
	char	*all_ans;
	int		flag_empty_line;

	flag_empty_line = 0;
	ans = get_next_line(fd);
	if (!ans)	
		ft_error2("Error\nthe map is empty\n", ptr);
	all_ans = ft_init_string(0);
	while (ans)
	{
		if (!ans)
			break ;
		if (*ans == '\n')
		{
			flag_empty_line = 1;
		}
		all_ans = ft_strjoin(all_ans, ans);
		free(ans);
		ans = get_next_line(fd);
	}
	(*ptr).tab_map = ft_split(all_ans, '\n');
	free(all_ans);
	if (!(*ptr).tab_map)
		ft_error2("Error\nthe map is not set correctly\n", ptr);
	if (close(fd) == -1)
		ft_error3("close() failed \n", ptr);
	if (flag_empty_line == 1)
		ft_error3("Error\n empty line is not authorized in map\n", ptr);
}
