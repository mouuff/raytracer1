/*
** tekpixel.c for tekpixel in /home/alies/rendu/gfx_fdf1/src/tek
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Nov 10 09:53:39 2015 Arnaud Alies
** Last update Tue Feb 16 10:39:51 2016 alies_a
*/

#include <lapin.h>

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  int   w;
  int	h;

  w = (pix->clipable).clip_width;
  h = (pix->clipable).clip_height;
  if ((pos->x < w && pos->y < h) && (pos->x >= 0 && pos->y >= 0))
    (((t_color*)pix->pixels)[w * pos->y + pos->x]).full = color->full;
}
