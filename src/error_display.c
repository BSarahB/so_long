/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:55:24 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/10 20:55:35 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s != 0)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}

int	ft_error2(char *const str, t_utils *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
	ft_putstr_fd(str, 2);
	exit (0);
}

int	ft_error3(char *const str, t_utils *ptr)
{
	if (ptr != NULL)
	{
		ft_free_struct_tab((*ptr).tab_map);
		free(ptr);
		ptr = NULL;
	}
	ft_putstr_fd(str, 2);
	exit (0);
}

int	ft_error_and_exit(char *const str)
{
	ft_putstr_fd(str, 2);
	exit (0);
}

void	ft_error(char *const str)
{
	ft_putstr_fd(str, 2);
}
