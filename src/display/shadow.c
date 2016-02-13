/*
** shadow.c for shadow in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Feb 11 18:23:42 2016 alies_a
** Last update Thu Feb 11 21:09:11 2016 alies_a
*/

#include "rt.h"

void		shadow(const t_data *data,
		       const t_hit *hit,
		       t_color *color)
{
  t_hit		new;
  t_ray		ray;

  ray.alpha = data->light;
  ray.beta = vec_unit(&(data->light), &(hit->hitpos));
  new = get_closest_obj(data, &ray);
  if (!new.hit)
    {
      color->full = BLACK;
      return ;
    }
  if (new.obj != hit->obj)
    color->full = BLACK;
}
