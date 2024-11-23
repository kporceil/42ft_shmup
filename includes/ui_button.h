/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:31:11 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 01:48:48 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_BUTTON_H
# define UI_BUTTON_H

typedef struct	s_ui_button
{
	int		y;
	int		x;
	char	*content;
	void	(*trigger)(void);
	void	*prev_highlight;
	void	*next_highlight;
	bool	mouse_clickable;
	bool	disabled;
}				t_ui_button;

// MEMORY
t_ui_button	*ft_new_btn(int y, int x, char *content, void (*trigger)(void), bool mouse_clickable);
void		ft_del_btn(t_ui_button *btn);

// UTILS
void		ft_render_btn(t_ui_button *btn, t_ui_button *highlight);
void		ft_move_btn(t_ui_button *btn, int y, int x);
int			ft_height_btn(t_ui_button *btn);
int			ft_width_btn(t_ui_button *btn);

#endif
