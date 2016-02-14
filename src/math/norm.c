/*
** norm.c for norm in /home/alies_a/rendu/gfx_raytracer1/src
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Jan 29 16:59:47 2016 alies_a
** Last update Sun Feb 14 19:34:13 2016 alies_a
*/

#include <math.h>
#include "rt.h"

double		vec_norm(const t_vec *Va, const t_vec *Vb)
{
  double	a;
  double	b;
  double	c;

  a = Vb->x - Va->x;
  b = Vb->y - Va->y;
  c = Vb->z - Va->z;
  return (sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2)));
}
