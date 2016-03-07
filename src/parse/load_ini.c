/*
** load_ini.c for load_ini in /home/alies_a/rendu/gfx_raytracer1/src/parse
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Mar  7 10:35:11 2016 alies_a
** Last update Mon Mar  7 13:22:00 2016 alies_a
*/

#include "rt.h"

int			load_ini(const char *file, t_objs *objs)
{
  t_bunny_ini		*ini;

  if ((ini = bunny_load_ini(file)) == NULL)
    return (1);
  if (load_objs(ini, objs))
    return (1);
  return (0);
}
