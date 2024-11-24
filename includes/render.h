/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:17:35 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 02:19:57 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

// CIRCULAR INCLUDE FIX
typedef struct s_game_data t_game_data;
typedef struct s_background_layer t_background_layer;

// COLORS
# define WHITE 1
# define BLUE 2
# define RED 3
# define RED_ON_MAGENTA 4
# define GREEN 5
# define YELLOW 6
# define CYAN 7
# define MAGENTA 8
# define BLACK_ON_WHITE 9

// GAME RENDER
void	ft_game_render(t_game_data *game_data);
void	ft_game_render_scene_borders(t_game_data *game_data);
void	ft_game_render_scene_background(t_game_data *game_data);
void	ft_game_init_background_layer(t_game_data *game_data, t_background_layer *layer);
void	ft_game_render_background_layer(t_game_data *game_data, t_background_layer *layer);
void	ft_game_unrender_background_layer(t_game_data *game_data, t_background_layer *layer);
void	ft_game_del_background(t_game_data *game_data);
void	ft_game_scene_size(t_game_data *game_data);

// NCURSES
void	ft_init_ncurses();
void	ft_del_ncurses();

#endif
