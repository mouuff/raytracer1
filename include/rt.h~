/*
** doom.h for doom in /home/alies/rendu/gfx_tekdoom/include
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Tue Jan 12 16:58:58 2016 Arnaud Alies
** Last update Tue Jan 26 19:05:03 2016 Frederic ODDOU
*/

#ifndef DOOM_H_
#define DOOM_H_

#define WIDTH (320)
#define HEIGHT (200)
#define FPS (40)
#define FOVX (1)
#define FOVY (0.7)
#define DIST (0.5)

#define MAP(x, sA, eA, sB, eB) ((((sA - x) / (sA - eA)) * (eB - sB)) + sB)
#define ABS(x) ((x) < 0 ? -(x) : (x))

#include <lapin.h>
#include "map.h"

typedef struct s_vec
{
  float x;
  float y;
  float z;
} t_vec;

typedef struct s_plane
{
  float	a;
  float	b;
  float	c;
  float	d;
} t_plane;

typedef struct s_me
{
  t_vec		pos;
  int		inair;
  float		fall;
  float		sprint;
  float		crowd;
  float		alpha;
  float		beta;
  int		fly;
  float		speedfront;
  float		speedside;
  int		pointed_mob;
} t_me;

typedef struct s_mob
{
  t_bunny_pixelarray	*tex;
  t_bunny_pixelarray	*tex_alive;
  t_bunny_pixelarray	*tex_hurt;
  t_bunny_pixelarray	*tex_dead;
  t_vec                 pos;
  t_vec                 size;
  t_plane		p;
  t_vec			dir;
  int			dead;
  float			speed;
} t_mob;

typedef struct s_select
{
  int selected;
  int open;
} t_select;

typedef struct s_gun
{
  t_bunny_pixelarray	*tex;
  t_bunny_effect	*sound;
  t_bunny_position	beg;
  t_bunny_position	end;
  t_bunny_position	size;
  t_bunny_position	frame_pos;
  float			speed;
  char			fire;
} t_gun;

typedef struct s_sound
{
  t_bunny_effect	*boom;
} t_sound;

typedef struct s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*texture;
  const bool		*keys;
  t_me			me;
  t_mob			*mob;
  t_map			*map;
  t_select		select;
  t_gun			gun;
  t_sound		sound;
  int			end;
  t_bunny_pixelarray	*end_pix;
} t_data;

/*
** Display
*/

#define MAX (99)
#define LIM(x) ((x) < -(MAX) ? -(MAX) : ((x) > MAX ? MAX : (x)))
#define VIEW_DIST (15)
#define PREC (0.0001)
#define NB_MOB (3)

typedef struct s_ray
{
  t_vec	alpha;
  t_vec	beta;
} t_ray;

typedef struct s_hit
{
  t_vec                 pt;
  char                  axe;
  float                 norm;
  t_bunny_position      ratio;
  t_pos                 blk;
  t_pos                 min;
  t_pos                 max;
  t_color		pix;
  char			mob;
} t_hit;

void    display(t_data *data);
void    test_mobs(t_data *data, t_ray *ray, t_hit *hit);
void    gen_mob_plane(t_data *data);
void    blow_at(t_data *data, t_pos *pos, int size);
int     init_mob(t_data *data);

void	test_x(t_data *data, t_ray *ray, t_hit *hit);
void	test_y(t_data *data, t_ray *ray, t_hit *hit);
void	test_z(t_data *data, t_ray *ray, t_hit *hit);

void    set_hit_info(t_hit *hit);
void    get_point(t_data *data, t_bunny_position *pos, t_hit *hit);
float   get_range(t_ray *ray, char plane, float lvl, t_vec *point);
void    calc_pos(t_vec *result, t_ray *param, float k);
int     map_check_pos(t_map *map, t_vec *vec);

void	stretch(t_bunny_pixelarray *pix,
		const t_bunny_pixelarray *ori);

void    display_gun(t_bunny_pixelarray *pix, t_gun *gun, t_data *data);

void	hurt_boss(t_data *data);
void	kill_boss(t_data *data);
void	viseur(t_data *data);

/*
** Core
*/

t_color	get_pixel(const t_bunny_pixelarray *pix,
		  t_bunny_position *pos);

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

double	vecnorm(t_bunny_position *coord0,
		t_bunny_position *coord1);

/*
** Initialize
*/

int	init_all(t_data *data, int ac, char **av);
void    delete_all(t_data *data);

/*
** Texture
*/

#define MAX_TEXT (96)

void	show_textures(t_data *data);

t_color	get_texture(t_data *data,
		    t_pos *block_x,
		    t_bunny_position *pos);

/*
** Mobs
*/

void    test_mobs(t_data *data, t_ray *ray, t_hit *hit);
void    mob_loop(t_data *data);
void    kill_all_in_zone(t_data *data, t_pos *pos);

int	map_limite_portee(t_data *data, t_hit hit);

#endif
