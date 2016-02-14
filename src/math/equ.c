/*
** equ.c for equ in /home/alies_a/rendu/gfx_raytracer1/src/objs
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Jan 29 14:48:16 2016 alies_a
** Last update Sun Feb 14 19:41:26 2016 alies_a
*/

#include <math.h>
#include "rt.h"

double   det(double a, double b, double c)
{
  return (pow(b, 2) - (4 * a * c));
}

t_ray	equ_para(const t_ray *ray, double t1, double t2)
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
