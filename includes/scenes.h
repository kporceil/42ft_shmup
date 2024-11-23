/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scenes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 02:20:16 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 03:55:50 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENES_H
# define SCENES_H

typedef enum	e_game_state
{
	STATE_EXIT,
	STATE_MAIN_MENU,
	STATE_SETTINGS,
	STATE_GAME
}				t_game_state;

extern t_game_state	state;

int	ft_main_menu();

#endif
