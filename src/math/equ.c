/*
** equ.c for equ in /home/alies_a/rendu/gfx_raytracer1/src/objs
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Jan 29 14:48:16 2016 alies_a
** Last update Sat Jan 30 11:09:17 2016 alies_a
*/

#include <math.h>
#include "rt.h"

float   det(float a, float b, float c)
{
  return (powf(b, 2) - (4 * a * c));
}

t_ray	equ_para(const t_ray *ray, float t1, float t2)
{
  t_ray	res;

  (res.alpha).x = (ray->alpha).x + (ray->beta).x * t1;
  (res.alpha).y = (ray->alpha).y + (ray->beta).y * t1;
  (res.alpha).z = (ray->alpha).z + (ray->beta).z * t1;
  (res.beta).x = (ray->alpha).x + (ray->beta).x * t2;
  (res.beta).y = (ray->alpha).y + (ray->beta).y * t2;
  (res.beta).z = (ray->alpha).z + (ray->beta).z * t2;
  return (res);
}
