/*
** shine.c for shine in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Feb 13 11:26:13 2016 alies_a
** Last update Mon Feb 15 18:57:58 2016 alies_a
*/

#include <math.h>
#include "rt.h"

void            phong(const t_data *data,
		      const t_hit *hit,
		      t_color *color)
{
  t_vec         obj_vec;
  t_vec         light_vec;
  double        prod;

  if (get_uni_vec(hit, &obj_vec))
    return ;
  light_vec =  vec_unit(&(data->light), &(hit->hitpos));
  prod = -vec_scal(&light_vec, &obj_vec);
  if (prod < 0)
    return ;
  prod = pow(prod, PHONG_POW);
  prod = (prod < 0 ? 0 : prod);
  prod = (prod > PHONG ? PHONG : prod);
  color->argb[0] = (255 - color->argb[0]) * prod + color->argb[0];
  color->argb[1] = (255 - color->argb[1]) * prod + color->argb[1];
  color->argb[2] = (255 - color->argb[2]) * prod + color->argb[2];
}
