/*
** rt.h for rt in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Jan 29 14:18:35 2016 alies_a
** Last update Sat Feb 13 11:49:20 2016 alies_a
*/

#ifndef RT_H_
#define RT_H_

#define WIDTH (500)
#define HEIGHT (500)
#define FPS (5)
#define FOVX (1)
#define FOVY (1)
#define DIST (0.5)

#define DIFF (0.7)
#define AMBI (50)

#define MAP(x, sA, eA, sB, eB) ((((sA - x) / (sA - eA)) * (eB - sB)) + sB)
#define ABS(x) ((x) < 0 ? -(x) : (x))

#include <lapin.h>

typedef struct s_vec
{
  float x;
  float y;
  float z;
} t_vec;

typedef struct s_ray
{
  t_vec alpha;
  t_vec beta;
} t_ray;

typedef struct s_cam
{
  float	alpha;
  float beta;
  t_vec pos;
} t_cam;

/*
** objs
*/

typedef struct s_obj
{
  char	type;
  t_vec pos;
  float	size;
  t_color color;
} t_obj;

typedef struct s_objs
{
  int	nb;
  t_obj	*objs;
} t_objs;

/*
** math
*/

typedef struct s_hit
{
  const t_obj	*obj;
  t_vec		hitpos;
  float		norm;
  int		hit;
} t_hit;

/*
** calc
*/

typedef struct s_cal
{
  float a;
  float b;
  float c;
  float d;
  float t1;
  float t2;
} t_cal;

/*
** shaders ptr
*/

typedef t_hit(*t_func)(const t_ray *ray, const t_obj *obj);
typedef t_vec(*t_uni)(const t_hit *hit);

typedef struct s_shader
{
  t_func func;
  t_uni uni;
  char type;
} t_shader;

t_func	get_func(char type);
t_uni	get_uni(char type);
int     get_uni_vec(const t_hit *hit, t_vec *vec);

/*
** base
*/

typedef struct s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  const bool		*keys;
  t_vec			light;
  t_cam			cam;
  t_objs		objs;
} t_data;

t_color	get_pixel(const t_bunny_pixelarray *pix,
		  t_bunny_position *pos);

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

/*
** math
*/

void	display(t_data *data);

int     is_visible(const t_ray *screen, const t_hit *hit);
float   det(float a, float b, float c);
t_ray   equ_para(const t_ray *ray, float t1, float t2);

t_hit	get_closest_obj(const t_data *data, const t_ray *ray);
void	render(const t_data *data,
	       const t_hit *hit,
	       t_color *color);
void	shadow(const t_data *data,
	       const t_hit *hit,
	       t_color *color);

float   vec_norm(const t_vec *Va, const t_vec *Vb);
float   vec_scal(const t_vec *a, const t_vec *b);
t_vec   vec_unit(const t_vec *a, const t_vec *b);

/*
** objects
*/

t_hit   sphere(const t_ray *ray, const t_obj *obj);
t_hit   plane_z(const t_ray *ray, const t_obj *obj);
t_hit   cylinder(const t_ray *ray, const t_obj *obj);

/*
** unit vec functions
*/

t_vec   center_vec(const t_hit *hit);
t_vec   up_vec(const t_hit *hit);

#endif
