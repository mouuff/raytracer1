/*
** equ.c for equ in /home/alies_a/rendu/gfx_raytracer1/src/objs
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Jan 29 14:48:16 2016 alies_a
** Last update Tue Feb 16 11:34:16 2016 alies_a
*/

#include <math.h>
#include "rt.h"

double   det(double a, double b, double c)
{
  return (pow(b, 2) - (4 * a * c));
}

t_vec	equ_para(const t_ray *ray, double t1)
{
  t_vec	res;

  res.x = (ray->alpha).x + (ray->beta).x * t1;
  res.y = (ray->alpha).y + (ray->beta).y * t1;
  res.z = (ray->alpha).z + (ray->beta).z * t1;
  return (res);
}
