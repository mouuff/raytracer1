/*
** find_vec.c for find vec in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Feb  8 23:26:02 2016 alies_a
** Last update Tue Feb  9 00:04:42 2016 alies_a
*/

#include "rt.h"

t_vec	center_vec(const t_hit *hit)
{
  return (vec_unit(&((hit->obj)->pos), &(hit->hitpos)));
}

t_vec	up_vec(const t_hit *hit)
{
  t_vec	new;

  new.x = (hit->hitpos).x;
  new.y = (hit->hitpos).y;
  new.z = (hit->hitpos).z + 1;
  return (vec_unit(&(hit->hitpos), &new));
}
