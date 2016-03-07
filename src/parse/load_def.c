/*
** load_def.c for load def in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Mar  7 13:37:38 2016 alies_a
** Last update Mon Mar  7 15:29:23 2016 alies_a
*/

#include "rt.h"

static void	set_def(t_objs *objs)
{
  ((objs->cam).pos).x = 5;
  ((objs->cam).pos).y = 5;
  ((objs->cam).pos).z = 5;
  (objs->cam).alpha = 0;
  (objs->cam).beta = 0;
  (objs->light).x = 0;
  (objs->light).y = 0;
  (objs->light).z = 0;
}

void		load_def(t_bunny_ini_scope *scope,
			 t_objs *objs)
{
  const char	*buff;
  
  set_def(objs);
  if ((buff = bunny_ini_scope_get_field(scope, "pos", 0)) != NULL)
    ((objs->cam).pos).x = my_str_to_nbr(buff);
  if ((buff = bunny_ini_scope_get_field(scope, "pos", 1)) != NULL)
    ((objs->cam).pos).y = my_str_to_nbr(buff);
  if ((buff = bunny_ini_scope_get_field(scope, "pos", 2)) != NULL)
    ((objs->cam).pos).z = my_str_to_nbr(buff);
  if ((buff = bunny_ini_scope_get_field(scope, "ang", 0)) != NULL)
    (objs->cam).alpha = my_str_to_nbr(buff) * M_PI / 180;
  if ((buff = bunny_ini_scope_get_field(scope, "ang", 1)) != NULL)
    (objs->cam).beta = my_str_to_nbr(buff) * M_PI / 180;
  if ((buff = bunny_ini_scope_get_field(scope, "light0", 0)) != NULL)
    (objs->light).x = my_str_to_nbr(buff);
  if ((buff = bunny_ini_scope_get_field(scope, "light0", 1)) != NULL)
    (objs->light).y = my_str_to_nbr(buff);
  if ((buff = bunny_ini_scope_get_field(scope, "light0", 2)) != NULL)
    (objs->light).z = my_str_to_nbr(buff);
}
