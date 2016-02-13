/*
** visible.c for is visible in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Jan 30 22:51:24 2016 alies_a
** Last update Sat Jan 30 23:02:17 2016 alies_a
*/

#include "rt.h"

int	is_visible(const t_ray *screen, const t_hit *hit)
{
  t_vec	vec;

  if (hit->hit == 0)
    return (0);
  vec.x = (screen->beta).x + (screen->alpha).x;
  vec.y = (screen->beta).y + (screen->alpha).y;
  vec.z = (screen->beta).z + (screen->alpha).z;
  if (hit->norm > vec_norm(&vec, &(hit->hitpos)))
    return (1);
  return (0);
}
