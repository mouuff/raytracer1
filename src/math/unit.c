/*
** unit.c for unnit in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Feb  8 13:19:07 2016 alies_a
** Last update Sun Feb 14 19:34:41 2016 alies_a
*/

#include <math.h>
#include "rt.h"

int     get_uni_vec(const t_hit *hit, t_vec *vec)
{
  t_uni uni;

  if ((uni = get_uni((hit->obj)->type)) == NULL)
    return (1);
  *vec = uni(hit);
  return (0);
}

t_vec		vec_unit(const t_vec *a, const t_vec *b)
{
  t_vec		res;
  double	n;

  res.x = b->x - a->x;
  res.y = b->y - a->y;
  res.z = b->z - a->z;
  n = sqrt((res.x * res.x) +
	   (res.y * res.y) +
	   (res.z * res.z));
  res.x /= n;
  res.y /= n;
  res.z /= n;
  return (res);
}
