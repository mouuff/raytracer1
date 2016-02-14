/*
** shine.c for shine in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Feb 13 11:26:13 2016 alies_a
** Last update Sun Feb 14 19:41:12 2016 alies_a
*/

float   vec_scal(const t_vec *a,
		 const t_vec *b)
{
  float res;

  res = (a->x * b->x) + (a->y * b->y) + (a->z * b->z);
  return (res);
}

t_color         shine(const t_data *data,
		      const t_hit *hit)
{
  t_color       res;
  t_vec         obj_vec;
  t_vec         light_vec;
  float         prod;

  res.full = BLACK;
  if (get_uni_vec(hit, &obj_vec))
    return (res);
  light_vec =  vec_unit(&(data->light), &(hit->hitpos));
  prod = vec_scal(&light_vec, &obj_vec);
  prod = (prod < 0 ? 0 : prod);
  prod = (prod > DIFF ? DIFF : prod);
  res.argb[0] = MAP((float)prod, 0, DIFF, ((hit->obj)->color).argb[0], 0);
  res.argb[1] = MAP((float)prod, 0, DIFF, ((hit->obj)->color).argb[1], 0);
  res.argb[2] = MAP((float)prod, 0, DIFF, ((hit->obj)->color).argb[2], 0);
  res.argb[3] = 255;
  return (res);
}
