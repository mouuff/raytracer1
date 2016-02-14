/*
** render.c for render in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Sun Feb  7 15:29:48 2016 alies_a
** Last update Sun Feb 14 19:36:24 2016 alies_a
*/

#include "rt.h"

void		render(const t_data *data,
		       const t_hit *hit,
		       t_color *color)
{
  t_vec		obj_vec;
  t_vec		light_vec;
  double	prod;

  if (get_uni_vec(hit, &obj_vec))
    return ;
  light_vec =  vec_unit(&(data->light), &(hit->hitpos));
  prod = vec_scal(&light_vec, &obj_vec);
  prod = (prod < 0 ? 0 : prod);
  prod = (prod > DIFF ? DIFF : prod);
  color->argb[0] = MAP((double)prod, 0, DIFF, color->argb[0], 0);
  color->argb[1] = MAP((double)prod, 0, DIFF, color->argb[1], 0);
  color->argb[2] = MAP((double)prod, 0, DIFF, color->argb[2], 0);
}
