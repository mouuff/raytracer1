/*
** load_item.c for item in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Mon Mar  7 12:55:58 2016 alies_a
** Last update Mon Mar  7 13:25:36 2016 alies_a
*/

#include "rt.h"
#include "my.h"

void		load_item(const t_bunny_ini_scope *scope,
			  t_obj *obj)
{
  const char	*buff;

  my_memset((void*)obj, 0, sizeof(t_obj));
  if ((buff = bunny_ini_scope_get_field(scope, "type", 0)) != NULL)
    obj->type = buff[0];
  if ((buff = bunny_ini_scope_get_field(scope, "pos", 0)) != NULL)
    (obj->pos).x = my_str_to_nbr(buff);
  if ((buff = bunny_ini_scope_get_field(scope, "pos", 1)) != NULL)
    (obj->pos).y = my_str_to_nbr(buff);
  if ((buff = bunny_ini_scope_get_field(scope, "pos", 2)) != NULL)
    (obj->pos).z = my_str_to_nbr(buff);
  if ((buff = bunny_ini_scope_get_field(scope, "size", 0)) != NULL)
    obj->size = my_str_to_nbr(buff);
  if ((buff = bunny_ini_scope_get_field(scope, "color", 0)) != NULL)
    ((obj->color).argb)[0] = my_str_to_nbr(buff);
  if ((buff = bunny_ini_scope_get_field(scope, "color", 1)) != NULL)
    ((obj->color).argb)[1] = my_str_to_nbr(buff);
  if ((buff = bunny_ini_scope_get_field(scope, "color", 2)) != NULL)
    ((obj->color).argb)[2] = my_str_to_nbr(buff);
}
