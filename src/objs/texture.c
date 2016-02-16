/*
** texture.c for texture in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Feb 15 20:32:22 2016 alies_a
** Last update Mon Feb 15 21:15:43 2016 alies_a
*/

#include "rt.h"

void	grid_texture(const t_data *data,
		     const t_hit *hit,
		     t_color *color)
{
  if ((hit->hitpos).x % 10 > 5 &&
      (hit->hitpos).y % 10 > 5)
    color->full = BLACK;
}

