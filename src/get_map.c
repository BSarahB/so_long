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

void	ft_get_images_id_aux(t_utils *ptr, char *str, void **asset)
{
	char	*str_joined;

	str_joined =  ft_strjoin2((*ptr).xpm_path, str);
	*asset = mlx_xpm_file_to_image \
			((*ptr).mlx, str_joined, &(*ptr).pixel_x, &(*ptr).pixel_y);
	ft_free_struct_str(&str_joined);
	if (!(*asset))
		ft_error_and_exit("Failed to load xpm ressources or asset\n");
}

void	ft_get_images_id(t_utils *ptr)
{
	ft_get_images_id_aux(ptr, "/avatar.xpm", &(*ptr).avatar);
	ft_get_images_id_aux(ptr, "/exit.xpm", &(*ptr).exit);
	ft_get_images_id_aux(ptr, "/npxfess.xpm", &(*ptr).collectible);
	ft_get_images_id_aux(ptr, "/scene.xpm", &(*ptr).scene);
	ft_get_images_id_aux(ptr, "/wall.xpm", &(*ptr).wall);
}
/*
void ft_resize(const char *src, int srcWidth, int srcHeight, char *dst, int dstWidth, int dstHeight, int numComponents)
{
	int srcPitch = srcWidth * numComponents;
//code fait une boucle examine le spixels fait la moyenne et les ecrit dans la destination
	float ratioX = (float)srcWidth / dstWidth;
	float ratioY = (float)srcHeight / dstHeight;

	for (int y = 0; y < dstHeight; y++) {
		int iY = y * ratioY;

		int offsetY = iY * srcPitch;

		for (int x = 0; x < dstWidth; x++) {
			int iX = x * ratioX;

			int offsetX = iX * numComponents;

			const char *srcPtrY = &src[offsetY];//const T *srcPtrY = &src[offsetY];

			for (int i = 0; i < numComponents; i++) {
				*dst++ = srcPtrY[offsetX + i];
			}
		}
	}
}

 void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);
void	*mlx_xpm_to_image(t_xvar *xvar,char **data,int *width,int *height)//ret un void *
{
  return (mlx_int_xpm_f_image(xvar,width,height,XpmCreateImageFromData,(void *)data));
}


//1fonction generique qui resize le pointeur et a l intrieur on alloue une image temporaire
void ft_resize_image(void *mlx, void *image, int new_w, int new_h)
{
	t_img	*img;
	char	*tmp_resized_data;
	char	*tmp_img_data;
	char	*img_data;
	void	*image_original;
	void	*image_resized;

	img = (t_img *)image;
	img_data = (*img).data;//on a acces aux pixels (ligne 92 mlx_int.h)

	image_original = image;//on memorise l adresse de l endroit o se trouve les pixels de l image
	tmp_resized_data = malloc(sizeof(char) * (new_h * new_w));//une image c est comme un tableau a 2 dimensions
	ft_resize(img_data, (*img).width, (*img).height, tmp_resized_data, new_w, new_h, 3);
	image_resized = mlx_xpm_to_image((t_xvar *)mlx, &tmp_resized_data, &new_w ,&new_h);

	*image = tmp_resized_data;
	mlx_destroy_image((*ptr).mlx, tmp_src);

}


*/
void	get_map(int fd, t_utils *ptr)
{
	char	*ans;
	char	*all_ans;
	int		flag_empty_line;

	flag_empty_line = 0;
	ans = get_next_line(fd);
	if (!ans)
	{
		free(ptr);
		ptr = NULL;
		ft_error_and_exit("Error\nthe map is empty\n");
	}
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
	{
		free(ptr);
		ptr = NULL;
		ft_error_and_exit("Error\nthe map is not set correctly\n");
	}
	if (close(fd) == -1)
	{
		ft_error("close() failed \n");
		ft_free_struct_tab((*ptr).tab_map);
		free(ptr);
		ptr = NULL;
		exit (0);
	}
	if (flag_empty_line == 1)
	{
		ft_free_struct_tab((*ptr).tab_map);
		free(ptr);
		ptr = NULL;
		ft_error_and_exit("Error\n empty line is not authorized in map\n");
		exit (0);
	}

}
