/*
** tekray.c for tekray in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Feb 16 10:46:18 2016 alies_a
** Last update Tue Feb 16 11:04:26 2016 alies_a
*/

#include <lapin.h>

void    tekray(const t_bunny_position *screen_info,
	       int *x,
	       int *y,
	       int *z)
{
  *x = screen_info[1].x - (screen_info[0].x / 2);
  *y = screen_info[1].y - (screen_info[0].y / 2);
  *z = 100;
}
