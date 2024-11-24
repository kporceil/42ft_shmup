/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_button.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jureix-c <jureix-c@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 23:31:11 by jureix-c          #+#    #+#             */
/*   Updated: 2024/11/23 02:52:33 by jureix-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_BUTTON_H
# define UI_BUTTON_H

# include <stdbool.h>

// Button struct
typedef struct	s_ui_button
{
	// Base values
	int		y;
	int		x;
	char	*content;
	void	(*trigger)(void);
	// Highlight system
	void	*prev_highlight;
	void	*next_highlight;
	// Visual extra
	bool	has_borders;
	int		y_padding;
	int		x_padding;
	// Flags
	bool	mouse_clickable;
	bool	disabled;
}				t_ui_button;

// MEMORY
t_ui_button	*ft_new_btn(int y, int x, char *content, void (*trigger)(void), bool mouse_clickable);
void		ft_del_btn(t_ui_button *btn);

// ACTIONS
void		ft_render_btn(const t_ui_button *btn, const t_ui_button *highlight);
void		ft_trigger_btn(const t_ui_button *btn);
void		ft_move_btn(t_ui_button *btn, int y, int x);

// UTILS
int			ft_height_btn(const t_ui_button *btn);
int			ft_width_btn(const t_ui_button *btn);
void		ft_free_btn_list(t_ui_button **btn_list);

// VISUAL EXTRA
void		ft_render_btn_extras(const t_ui_button *btn);

#endif
