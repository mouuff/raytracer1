/*
** cylinder.c for cylinder in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Feb  6 10:09:20 2016 alies_a
** Last update Sat Feb 13 11:18:31 2016 alies_a
*/

#include <math.h>
#include "rt.h"

static void     set_hit_info(t_hit *hit,
			     const t_vec *start,
			     const t_ray *res,
			     const t_obj *obj)
{
  float         alpha;
  float         beta;

  alpha = vec_norm(start, &(res->alpha));
  beta = vec_norm(start, &(res->beta));
  hit->norm = (alpha > beta ? beta : alpha);
  hit->hitpos = (alpha > beta ? res->beta : res->alpha);
  hit->obj = obj; 
}

t_hit   cylinder(const t_ray *ray, const t_obj *obj)
{
  t_hit	res;
  t_ray	intsec;
  t_cal	calc;

  res.hit = 0;
  if ((ray->beta).x == 0 && (ray->beta).y == 0)
    return (res);
  calc.a = (powf((ray->beta).x, 2) +
	    powf((ray->beta).y, 2));
  calc.b = 2 * (((ray->beta).x) * ((ray->alpha).x - (obj->pos).x) +
		((ray->beta).y) * ((ray->alpha).y - (obj->pos).y));
  calc.c = powf((ray->alpha).x, 2) + powf((ray->alpha).y, 2) +
    powf((obj->pos).x, 2) + powf((obj->pos).y, 2) - 2 *
    (((ray->alpha).x * (obj->pos).x) +
     ((ray->alpha).y * (obj->pos).y)) - powf(obj->size, 2);
  calc.d = det(calc.a, calc.b, calc.c);
  if (calc.d < 0)
    return (res);
  if (calc.d >= 0)
    {
      res.hit = 1;
      calc.t1 = (-calc.b + sqrtf(calc.d)) / (2 * calc.a);
      calc.t2 = (-calc.b - sqrtf(calc.d)) / (2 * calc.a);
      intsec = equ_para(ray, calc.t1, calc.t2);
      set_hit_info(&res, &(ray->alpha), &intsec, obj);
      res.hit = (is_visible(ray, &res) ? 1 : 0);
    }
  return (res);
}
