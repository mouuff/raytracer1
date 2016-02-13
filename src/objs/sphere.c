/*
** sphere.c for sphere in /home/alies_a/rendu/gfx_raytracer1/src/objs
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Jan 29 14:40:57 2016 alies_a
** Last update Sat Feb 13 10:33:26 2016 alies_a
*/

#include <math.h>
#include "rt.h"

static void	set_hit_info(t_hit *hit,
			     const t_vec *start,
			     const t_ray *res,
			     const t_obj *obj)
{
  float		alpha;
  float		beta;

  alpha = vec_norm(start, &(res->alpha));
  beta = vec_norm(start, &(res->beta));
  hit->norm = (alpha > beta ? beta : alpha);
  hit->hitpos = (alpha > beta ? res->beta : res->alpha);
  hit->obj = obj;
}

t_hit	sphere(const t_ray *ray, const t_obj *obj)
{
  t_hit	res;
  t_ray intsec;
  t_cal calc;
  
  calc.a = (powf((ray->beta).x, 2) + powf((ray->beta).y, 2) +
	    powf((ray->beta).z, 2));
  calc.b = 2 * (((ray->beta).x) * ((ray->alpha).x - (obj->pos).x) +
		((ray->beta).y) * ((ray->alpha).y - (obj->pos).y) +
		((ray->beta).z) * ((ray->alpha).z - (obj->pos).z));
  calc.c = powf((ray->alpha).x, 2) + powf((ray->alpha).y, 2) +
    powf((ray->alpha).z, 2) + powf((obj->pos).x, 2) +
    powf((obj->pos).y, 2) + powf((obj->pos).z, 2) - 2 *
    (((ray->alpha).x * (obj->pos).x) + ((ray->alpha).y * (obj->pos).y) +
     ((ray->alpha).z * (obj->pos).z)) - powf(obj->size, 2);
  calc.d = det(calc.a, calc.b, calc.c);
  res.hit = 1;
  if (calc.d < 0)
    {
      res.hit = 0;
      res.norm = 0;
      return (res);
    }
  calc.t1 = (-calc.b + sqrtf(calc.d)) / (2 * calc.a);
  calc.t2 = (-calc.b - sqrtf(calc.d)) / (2 * calc.a);
  intsec = equ_para(ray, calc.t1, calc.t2);
  set_hit_info(&res, &(ray->alpha), &intsec, obj);
  res.hit = (is_visible(ray, &res) ? 1 : 0);
  return (res);
}
