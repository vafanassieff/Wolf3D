/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libesdl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafanass <vafanass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:14:03 by vafanass          #+#    #+#             */
/*   Updated: 2017/06/11 19:37:58 by vafanass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBESDL_H
# define _LIBESDL_H

# include <SDL.h>

typedef struct	s_text
{
	SDL_Texture		*text;
	SDL_Rect		rect;
}				t_text;

typedef struct	s_input
{
	char			key[SDL_NUM_SCANCODES];
	char			button[8];
	int				mw_y;
	int				m_x;
	int				m_y;
	int				m_r_x;
	int				m_r_y;
	char			quit;
	char			window;
}				t_input;

typedef struct	s_engine
{
	SDL_Window		*win;
	int				rx;
	int				ry;
	SDL_Renderer	*render;
	t_input			*input;
}				t_engine;

typedef	struct	s_esdl
{
	t_engine		eng;
	int				run;
}				t_esdl;

/*
** eSDL
*/

int				esdl_init(t_esdl *esdl, const int rx, const int ry, char *name);
SDL_Surface		*esdl_create_surface(int width, int height);
void			remove_color_from_surface(SDL_Surface *surface, uint32_t color);
void			fill_surface(SDL_Surface *surface, uint32_t color);

void			esdl_update_events(t_input *in);
int				esdl_check_input(t_input *in, const int input);

void			esdl_put_pixel(SDL_Surface *surf, const int x, const int y,
				const int color);
Uint32			esdl_read_pixel(SDL_Surface *surf, const int x, const int y);

void			esdl_exit(t_esdl *esdl);

#endif
