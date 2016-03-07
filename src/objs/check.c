/*
** check.c for check in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Jan 30 22:22:32 2016 alies_a
** Last update Sun Mar  6 21:07:55 2016 alies_a
*/

#include "rt.h"

t_shader shaders[] =
  {{'s', &sphere, &center_vec},
   {'z', &plane_z, &up_vec},
   {'c', &cylinder, &cyl_vec},
   {0, NULL, NULL}};

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
