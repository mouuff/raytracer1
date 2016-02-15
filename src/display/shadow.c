/*
** shadow.c for shadow in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Thu Feb 11 18:23:42 2016 alies_a
** Last update Mon Feb 15 17:37:21 2016 alies_a
*/

#include "rt.h"

static void	ambient(t_color *color)
{
  (color->argb)[0] *= AMBI;
  (color->argb)[1] *= AMBI;
  (color->argb)[2] *= AMBI;
}

int		shadow(const t_data *data,
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
      ambient(color);
      return (1);
    }
  if (new.obj != hit->obj)
    {
      ambient(color);
      return (1);
    }
  return (0);
}
