/*
** norm.c for norm in /home/alies_a/rendu/gfx_raytracer1/src
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Jan 29 16:59:47 2016 alies_a
** Last update Sat Jan 30 11:10:22 2016 alies_a
*/

#include <math.h>
#include "rt.h"

float	vec_norm(const t_vec *Va, const t_vec *Vb)
{
  float	a;
  float	b;
  float	c;

  a = Vb->x - Va->x;
  b = Vb->y - Va->y;
  c = Vb->z - Va->z;
  return (sqrtf(powf(a, 2) + powf(b, 2) + powf(c, 2)));
}
