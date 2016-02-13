/*
** display.c for disp in /home/alies_a/rendu/gfx_raytracer1/src/display
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Jan 29 19:00:03 2016 alies_a
** Last update Sat Feb 13 11:48:40 2016 alies_a
*/

#include <lapin.h>
#include <math.h>
#include "rt.h"

static void    get_ray(const t_cam *me,
		       const t_bunny_position *sr,
		       t_ray *ray)
{
  t_vec res;
  float beta;

  beta = -me->beta;
  res.x = DIST;
  res.y = FOVX * (((WIDTH / 2) - (float)sr->x) / WIDTH);
  res.z = FOVY * (((HEIGHT / 2) - (float)sr->y) / HEIGHT);
  ray->beta.x = res.x * cos(beta) + res.z * sin(beta);
  ray->beta.z = res.z * cos(beta) - res.x * sin(beta);
  res.x = ray->beta.x;
  ray->beta.x = res.x * cos(me->alpha) - res.y * sin(me->alpha);
  ray->beta.y = res.x * sin(me->alpha) + res.y * cos(me->alpha);
  ray->alpha.x = me->pos.x;
  ray->alpha.y = me->pos.y;
  ray->alpha.z = me->pos.z;
}

t_hit		get_closest_obj(const t_data *data, const t_ray *ray)
{
  t_func	func;
  t_hit		min;
  t_hit		buff;
  int		x;

  x = 0;
  min.hit = 0;
  min.norm = 0;
  while (x < (data->objs).nb)
    {
      if ((func = get_func((((data->objs).objs)[x]).type)) != NULL)
	{
	  buff = func(ray, &(((data->objs).objs)[x]));
	  if (min.hit == 0 || (buff.hit == 1 && buff.norm < min.norm))
	    {
	      min = buff;
	    }
	}
      x += 1;
    }
  return (min);
}

void		set_pix(t_data *data, t_bunny_position *pos)
{
  t_color	color;
  t_ray		ray;
  t_hit		hit;

  color.full = BLACK;
  get_ray(&(data->cam), pos, &ray);
  hit = get_closest_obj(data, &ray);
  if (hit.norm > 0 && hit.norm < 100 && hit.hit)
    {
      color = hit.obj->color;
      render(data, &hit, &color);
      shadow(data, &hit, &color);
      //debug
      if (pos->x == WIDTH / 2 && pos->y == HEIGHT / 2)
	{
	  color.full = RED;
	  if (data->keys != NULL && (data->keys)[BKS_O])
	    {
	      if (hit.obj != &(((data->objs).objs)[3]))
		{
		  (((data->objs).objs)[3].pos).x = (hit.hitpos).x;
		  (((data->objs).objs)[3].pos).y = (hit.hitpos).y;
		  (((data->objs).objs)[3].pos).z = (hit.hitpos).z;
		}
	      printf("------\n");
	      printf("Real : %f %f %f\n", (hit.hitpos).x, (hit.hitpos).y, (hit.hitpos).z);
	      printf("Obj  : %f %f %f\n", (hit.obj)->pos.x, (hit.obj)->pos.y, (hit.obj)->pos.z);
	      printf("Norm : %f\n", (hit.norm));
	      printf("------\n");
	    }
	}
      //end debug
    }
  tekpixel(data->pix, pos, &color);
}

void			display(t_data *data)
{
  t_bunny_position	pos;

  pos.x = 0;
  pos.y = 0;
  while (pos.y < HEIGHT)
    {
      set_pix(data, &pos);
      pos.x += 1;
      if (!(pos.x < WIDTH))
	{
	  pos.x = 0;
	  pos.y += 1;
	}
    }
}
