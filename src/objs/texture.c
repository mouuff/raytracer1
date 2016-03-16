/*
** texture.c for texture in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Feb 15 20:32:22 2016 alies_a
** Last update Mon Mar  7 16:52:05 2016 alies_a
*/

#include "rt.h"

void	grid_texture(const t_data *data,
		     const t_hit *hit,
		     t_color *color)
{
  int	rev;
  int	x;
  int	y;

  (void)data;
  rev = 0;
  if ((hit->hitpos).x * (hit->hitpos).y < 0)
    rev = 1;
  x = ABS((hit->hitpos).x);
  y = ABS((hit->hitpos).y);
  if ((x % SIZE_GRID * 2 >= SIZE_GRID &&
       y % SIZE_GRID * 2 >= SIZE_GRID) ||
      (x % SIZE_GRID * 2 < SIZE_GRID &&
       y % SIZE_GRID * 2 < SIZE_GRID))
    color->full = (rev ? WHITE : BLACK);
  else
    color->full = (rev ? BLACK : WHITE);
}

