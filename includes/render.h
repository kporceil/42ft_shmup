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

// NCURSES
void	ft_init_ncurses();
void	ft_del_ncurses();

#endif
