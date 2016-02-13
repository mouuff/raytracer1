/*
** check.c for check in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Jan 30 22:22:32 2016 alies_a
** Last update Thu Feb 11 19:43:26 2016 alies_a
*/

#include "rt.h"

t_shader shaders[] =
  {{&sphere, &center_vec, 's'},
   {&plane_z, &up_vec, 'z'},
   {&cylinder, &center_vec, 'c'},
   {NULL, NULL, 0}};

t_func  get_func(char type)
{
  int	x;

  x = 0;
  while (shaders[x].type != 0)
    {
      if (shaders[x].type == type)
	return (shaders[x].func);
      x += 1;
    }
  return (NULL);
}

t_uni  get_uni(char type)
{
  int	x;

  x = 0;
  while (shaders[x].type != 0)
    {
      if (shaders[x].type == type)
	return (shaders[x].uni);
      x += 1;
    }
  return (NULL);
}
