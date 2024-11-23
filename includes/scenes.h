/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:20:16 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 05:50:57 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENES_H
# define SCENES_H

# include <stdbool.h>

# include "ui_button.h"

typedef enum	e_game_state
{
	STATE_EXIT,
	STATE_MAIN_MENU,
	STATE_SETTINGS,
	STATE_GAME
}				t_game_state;

extern t_game_state	state;
extern bool			loop;

int		ft_main_menu();
void	ft_main_menu_input(bool *should_render, t_ui_button **current_highlight);
void	ft_main_menu_render(const t_ui_button **btns, const t_ui_button *current_highlight);

#endif
