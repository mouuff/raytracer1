/*
** plane.c for plane in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Sun Jan 31 14:03:13 2016 alies_a
** Last update Sun Feb 14 19:37:27 2016 alies_a
*/

#include "rt.h"

t_hit		plane_z(const t_ray *ray, const t_obj *obj)
{
  t_hit		res;
  double	k;

  k = (ray->alpha).z / -(ray->beta).z;
  res.hitpos.x = ((ray->beta).x * k + (ray->alpha).x);
  res.hitpos.y = ((ray->beta).y * k + (ray->alpha).y);
  res.hitpos.z = 0 ;
  res.norm = vec_norm(&(ray->alpha), &(res.hitpos));
  res.hit = (k > 0 ? 1 : 0);
  res.obj = obj;
  return (res);
}
