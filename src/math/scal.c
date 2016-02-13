/*
** scal.c for scal in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Sun Feb  7 15:03:33 2016 alies_a
** Last update Mon Feb  8 18:37:31 2016 alies_a
*/

#include <math.h>
#include "rt.h"

float	vec_scal(const t_vec *a,
		 const t_vec *b)
{
  float	res;

  res = (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
  return (res);
}
