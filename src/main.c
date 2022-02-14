/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:33:17 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/10 15:35:58 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_move(t_utils *ptr, int key)
{
	ft_destroy_and_update_image(ptr, key);
	if (ptr->tab_map[ptr->avatar_pos_y][ptr->avatar_pos_x] == 'E'
			&& (*ptr).nb_of_collectibles == 0)
		ft_take_exit(ptr, key);
	else if (ptr->tab_map[ptr->avatar_pos_y][ptr->avatar_pos_x] == '1'
			|| ptr->tab_map[(*ptr).avatar_pos_y][(*ptr).avatar_pos_x] == 'E')
		ft_push_back(ptr, key);
	else
		ft_move_on(ptr, key);
}

void	ft_call_move(t_utils *ptr, int key)
{
	if (key == RIGHT || key == D)
		(*ptr).avatar_pos_x += 1;
	else if (key == LEFT || key == A)
		(*ptr).avatar_pos_x -= 1;
	else if (key == W || key == UP)
		(*ptr).avatar_pos_y -= 1;
	else if (key == DOWN || key == S)
		(*ptr).avatar_pos_y += 1;
	ft_move(ptr, key);
}

int	deal_key(int key, t_utils *ptr)
{
	if (key == ESC || key == Q)
		ft_free_and_exit(ptr);
	else if (!ptr->finish && (key == W || key == A || key == S || \
						key == D || key == UP || key == DOWN || \
						key == LEFT || key == RIGHT))
	{
		ft_call_move(ptr, key);
		printf("move nb: %d\n", (*ptr).move_count);
	}
	if (ptr ->finish == 1)
	{
		printf("congratulations! you won! so chami!\nRelaunch to play again!\n");
		ft_free_and_exit(ptr);
	}
	return (0);
}

void	ft_rescale(t_utils *ptr)
{
	float	ratio_x;
	float	ratio_y;
	float	smallest_ratio;
	char	*xpm_size_string;

	mlx_get_screen_size((*ptr).mlx, &ptr->screen_x, &ptr->screen_y);
	ratio_x = (float)((*ptr).screen_x - SCREEN_OFFSET_X) / (*ptr).x;
	ratio_y = (float)((*ptr).screen_y  - SCREEN_OFFSET_Y) /(*ptr).y;
	smallest_ratio = ft_minimum(ratio_x, ratio_y);
	if (smallest_ratio < 1)
	{
		(*ptr).xpm_size = (int)(smallest_ratio * DEFAULT_XPM_SIZE);
		if ((*ptr).xpm_size < MIN_XPM_SIZE)
		{
			//forcer
			(*ptr).xpm_size = MIN_XPM_SIZE;
		}
		(*ptr).y = ft_get_size_of_tabmap((*ptr).tab_map) * (*ptr).xpm_size;
		(*ptr).x = ft_strlen((*ptr).tab_map[0]) * (*ptr).xpm_size;
	}
	xpm_size_string = ft_itoa((*ptr).xpm_size);
	(*ptr).xpm_path = ft_strjoin2("assets/images/xpm/", xpm_size_string);
	free(xpm_size_string);
}


void	ft_initialize(t_utils *ptr)
{
	(*ptr).mlx = mlx_init();
	if (!(*ptr).mlx)
		ft_error_and_exit("mlx_init() fails to set up the connection to the X server\n");

	ft_rescale(ptr);
	(*ptr).win = mlx_new_window((*ptr).mlx, (*ptr).x, (*ptr).y, "so_long");
	if (!(*ptr).mlx)
		ft_error_and_exit("mlx_new_window() fails to create a new window\n");

	ft_get_images_id(ptr);
	//ft_push_assets_to_window(ptr, (*ptr).tab_map);	//xvar->win_list = new_win;
	//mlx_int_anti_resize_win(((t_xvar *)(*ptr).mlx), ((t_win_list *)((*ptr).win))->window, 400, 400);
	//mlx_int_anti_resize_win(((t_xvar *)(*ptr).mlx), ((t_xvar *)((*ptr).mlx))->win_list->window, 400, 400); //(t_xvar *xvar,Window win,int w,int h)

	ft_push_assets_to_window(ptr, (*ptr).tab_map);
	mlx_key_hook((*ptr).win, deal_key, ptr);
	mlx_hook((*ptr).win, 33, 1L << 17, ft_free_and_exit, ptr);
	mlx_loop((*ptr).mlx);
}

float	ft_minimum(float x, float y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int	main(int ac, char *argv[])
{
	t_utils	*ptr;
	int		fd;

	ptr = ft_struct_init_utils(&ptr);
	if (ac == 2)
	{
		fd = ft_check_error_file(argv, ptr);
		get_map(fd, ptr);
		if (ft_check_map_validity(ptr))
		{
			(*ptr).y = ft_get_size_of_tabmap((*ptr).tab_map) * DEFAULT_XPM_SIZE;
			(*ptr).x = ft_strlen((*ptr).tab_map[0]) * DEFAULT_XPM_SIZE;
		}
		ft_initialize(ptr);
	}
	else
	{
		free(ptr);
		ptr = NULL;
		ft_error_and_exit("Error\nusage: ./so_long map.ber\n");
	}
	return (0);
}
