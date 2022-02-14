/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenmesb <mbenmesb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:24:48 by mbenmesb          #+#    #+#             */
/*   Updated: 2022/02/12 00:24:52 by mbenmesb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"
# define ITEM_CODE "01PCE"
# define ESC 65307
# define Q 113
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define W 119
# define A 97
# define S 115
# define D 100
# define DEFAULT_XPM_SIZE 32
# define MIN_XPM_SIZE 1
# define SCREEN_OFFSET_X 80 //pour compenser le menu de cote
# define SCREEN_OFFSET_Y 70 //pour compenser le bandeau et la barre de la fenetre

typedef struct s_utils {
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		screen_x;
	int		screen_y;
	int		pixel_x;
	int		pixel_y;
	int		xpm_size;
	char	*xpm_path;
	char	**tab_map;
	int		nb_of_players;
	int		nb_of_collectibles;
	int		nb_of_exits;
	int		move_count;
	int		start;
	int		finish;
	void	*scene;
	void	*avatar;
	void	*wall;
	void	*collectible;
	void	*exit;
	int		avatar_pos_x;
	int		avatar_pos_y;
}				t_utils;

t_utils		*ft_struct_init_utils(t_utils **ptr);
void		get_map(int fd, t_utils *ptr);
int			ft_check_error_file(char **argv, t_utils *ptr);
int			ft_check_invalid_format(char **argv, t_utils *ptr);
int			ft_check_map_validity(t_utils *ptr);
int			ft_check_map_border(t_utils *ptr);
int			ft_get_size_of_tabmap(char **tab_map);
int			ft_isrectangle(char **tab_map, t_utils *ptr);
void		ft_get_items_number(char *tab_line, t_utils *ptr);
void		ft_check_number_of_items(t_utils *ptr);
void		ft_get_images_id(t_utils *ptr);
int			ft_push_assets_to_window(t_utils *ptr, char **tab_map);
void		ft_move(t_utils *ptr, int key);
void		ft_destroy_and_update_image(t_utils *ptr, int key);
void		ft_move_on(t_utils *ptr, int key);
void		ft_push_back(t_utils *ptr, int key);
void		ft_take_exit(t_utils *ptr, int key);
void		ft_set_abandonned_square_to_0(t_utils *ptr, int key);
char		*ft_strrchr(const char *s, int c);
char		*ft_strjoin2(char const *s1, char const *s2);
char		*ft_not_strchr(const char *s, int c);
int			ft_strlen(const char *str);
int			ft_strcmp(char *s1, char *s2);
void		ft_error(char *const str);
void		ft_putstr_fd(char *s, int fd);
void		ft_free_struct_utils(t_utils *ptr);
void		ft_free_struct_tab(char **p);
void		ft_free_struct_t_img(t_img **p);
void		ft_free_struct_elem(void **p);
void		ft_free_struct_str(char **p);
int			ft_free_and_exit(t_utils *ptr);
char		**ft_split(char const *s, char c);
void		ft_putstr_fd(char *s, int fd);
void		ft_error(char *const str);
int			ft_error_and_exit(char *const str);
int			ft_strcmp(char *s1, char *s2);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strrchr(const char *s, int c);
float		ft_minimum(float x, float y);
char		*ft_itoa(int n);
void		ft_rescale(t_utils *ptr);



#endif
