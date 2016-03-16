/*
** cylinder.c for cylinder in /home/alies_a/rendu/gfx_raytracer1
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Sat Feb  6 10:09:20 2016 alies_a
** Last update Mon Mar  7 17:17:24 2016 alies_a
*/

#include <math.h>
#include "rt.h"

static void	set_hit_info(t_hit *hit,
			     const t_vec *start,
			     const t_obj *obj)
{
  hit->norm = vec_norm(start, &(hit->hitpos));
  hit->obj = obj;
  hit->hit = 1;
}

t_hit		cylinder(const t_ray *ray, const t_obj *obj)
{
  t_hit		res;
  t_cal		calc;

  if ((ray->beta).x == 0 && (ray->beta).y == 0)
    return (res);
  calc.a = (pow((ray->beta).x, 2) +
	    pow((ray->beta).y, 2));
  calc.b = 2 * (((ray->beta).x) * ((ray->alpha).x - (obj->pos).x) +
		((ray->beta).y) * ((ray->alpha).y - (obj->pos).y));
  calc.c = pow((ray->alpha).x, 2) + pow((ray->alpha).y, 2) +
    pow((obj->pos).x, 2) + pow((obj->pos).y, 2) - 2 *
    (((ray->alpha).x * (obj->pos).x) +
     ((ray->alpha).y * (obj->pos).y)) - pow(obj->size, 2);
  calc.d = det(calc.a, calc.b, calc.c);
  res.hit = 0;
  if (calc.d < 0)
    return (res);
  calc.t1 = (-calc.b + sqrt(calc.d)) / (2 * calc.a);
  calc.t2 = (-calc.b - sqrt(calc.d)) / (2 * calc.a);
  if (calc.t1 < 0 || calc.t2 < 0)
    return (res);
  res.hitpos = equ_para(ray, (calc.t1 > calc.t2 ? calc.t2 : calc.t1));
  set_hit_info(&res, &(ray->alpha), obj);
  return (res);
}
