/*
** load_objs.c for objs in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Mar  7 12:45:49 2016 alies_a
** Last update Mon Mar  7 13:37:18 2016 alies_a
*/

#include "rt.h"

static int              load_loop(t_bunny_ini *ini,
				  t_objs *objs)
{
  t_bunny_ini_scope     *scope;
  int                   x;

  if ((scope = bunny_ini_first(ini)) == NULL)
    return (1);
  load_def(scope, objs);
  scope = bunny_ini_next(ini, scope);
  x = 0;
  while (scope != NULL && x < objs->nb)
    {
      load_item(scope, &((objs->objs)[x]));
      scope = bunny_ini_next(ini, scope);
      x += 1;
    }
  return (0);
}

int			load_objs(t_bunny_ini *ini,
				  t_objs *objs)
{
  t_bunny_ini_scope     *scope;

  if ((scope = bunny_ini_first(ini)) == NULL)
    return (1);
  scope = bunny_ini_next(ini, scope);
  objs->nb = 0;
  while (scope != NULL)
    {
      scope = bunny_ini_next(ini, scope);
      objs->nb += 1;
    }
  if ((objs->objs = bunny_malloc(sizeof(t_obj) * objs->nb)) == NULL)
    return (1);
  if (load_loop(ini, objs))
    return (1);
  return (0);
}
