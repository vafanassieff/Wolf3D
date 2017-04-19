/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libesdl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:14:03 by qfremeau          #+#    #+#             */
/*   Updated: 2017/03/22 20:46:23 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBESDL_H
# define _LIBESDL_H

# include <SDL.h>
# include <SDL_ttf.h>
# include <SDL_image.h>

typedef struct	s_font
{
	TTF_Font		*font;
	SDL_Color		color;

}				t_font;

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

typedef struct	s_timer
{
	int				fps;
	int				current;
	int				update;
	int				limit;
	char			title[128];
	UINT			framelimit;
}				t_timer;

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
	t_timer			fps;
	int				run;
	int				ttf;
	int				img;
}				t_esdl;

/*
** eSDL
*/

int				esdl_init(t_esdl *esdl, const int rx, const int ry, char *name);
SDL_Surface		*esdl_create_surface(int width, int height);
SDL_Surface		*esdl_scale_surface(SDL_Surface *surf, int width, int height);

void			esdl_update_events(t_input *in, int *run);
int				esdl_check_input(t_input *in, const int input);

void			esdl_fps_limit(t_esdl *esdl);
void			esdl_fps_counter(t_esdl *esdl);

int				esdl_color_to_int(SDL_Color color);
SDL_Color		esdl_int_to_color(int color);
void			esdl_put_pixel(SDL_Surface *surf, const int x, const int y,
				const int color);
Uint32			esdl_read_pixel(SDL_Surface *surf, const int x, const int y);

SDL_Rect		*esdl_copy_rect(const SDL_Rect rect);
SDL_Rect		esdl_rect(const int x, const int y, const int w, const int h);
SDL_Rect		esdl_fuse_rect(const SDL_Rect dst, const SDL_Rect src);

void			esdl_draw_filled_square(SDL_Surface *surf,
				const SDL_Rect *rect, const int color, void *param);
void			esdl_clear_surface(SDL_Surface *surf,
				const SDL_Rect *rect, const int color, void *param);

void			esdl_exit(t_esdl *esdl);

/*
** SDL_TTF
*/

int				esdl_init_ttf(t_esdl *esdl);

t_font			esdl_load_font(char *name, int size, int color);
t_text			esdl_render_blendedtext(char *text, t_font f, int xy[2],
				SDL_Renderer *render);
t_text			esdl_render_solidtext(char *text, t_font f, int xy[2],
				SDL_Renderer *render);

/*
** SDL_IMG
*/

int				esdl_init_img(t_esdl *esdl);

SDL_Texture		*esdl_load_texture(SDL_Renderer *render,
				const char *path, int *w, int *h);

#endif
