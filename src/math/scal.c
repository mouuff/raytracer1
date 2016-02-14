/*
** scal.c for scal in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Sun Feb  7 15:03:33 2016 alies_a
** Last update Sun Feb 14 19:35:02 2016 alies_a
*/

#include <math.h>
#include "rt.h"

double		vec_scal(const t_vec *a,
			 const t_vec *b)
{
  double	res;

  res = (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
  return (res);
}
