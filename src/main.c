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
		printf("congratulations!you won!So Chami!\nRelaunch to play again!\n");
		ft_free_and_exit(ptr);
	}
	return (0);
}

void	ft_initialize(t_utils *ptr)
{
	(*ptr).mlx = mlx_init();
	if (!(*ptr).mlx)
		ft_error3("mlx_init() fails to set up connection to Xserver\n", ptr);
	ft_rescale(ptr);
	(*ptr).win = mlx_new_window((*ptr).mlx, (*ptr).x, (*ptr).y, "so_long");
	if (!(*ptr).win)
	{
		ft_free_struct_utils(ptr);
		ft_error_and_exit("mlx_new_window() fails to create a new window\n");
	}
	ft_get_images_id(ptr);
	ft_push_assets_to_window(ptr, (*ptr).tab_map);
	mlx_key_hook((*ptr).win, deal_key, ptr);
	mlx_hook((*ptr).win, 33, 1L << 17, ft_free_and_exit, ptr);
	mlx_loop((*ptr).mlx);
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
		ft_error2("Error\nusage: ./so_long map.ber\n", ptr);
	return (0);
}
