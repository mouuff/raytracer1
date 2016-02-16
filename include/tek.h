/*
** tek.h for tek in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Tue Feb 16 10:35:28 2016 alies_a
** Last update Tue Feb 16 10:41:01 2016 alies_a
*/

#ifndef TEK_H_
#define TEK_H_

void    tekpixel(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color);

void	tekray(const t_bunny_position *screen_info,
	       int *x,
	       int *y,
	       int *z);

#endif
