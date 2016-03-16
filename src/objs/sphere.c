/*
** sphere.c for sphere in /home/alies_a/rendu/gfx_raytracer1/src/objs
** 
** Made by alies_a
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Jan 29 14:40:57 2016 alies_a
** Last update Mon Mar  7 17:16:39 2016 alies_a
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

t_hit		sphere(const t_ray *ray, const t_obj *obj)
{
  t_hit		res;
  t_cal 	calc;

  calc.a = (pow((ray->beta).x, 2) + pow((ray->beta).y, 2) +
	    pow((ray->beta).z, 2));
  calc.b = 2 * (((ray->beta).x) * ((ray->alpha).x - (obj->pos).x) +
		((ray->beta).y) * ((ray->alpha).y - (obj->pos).y) +
		((ray->beta).z) * ((ray->alpha).z - (obj->pos).z));
  calc.c = pow((ray->alpha).x, 2) + pow((ray->alpha).y, 2) +
    pow((ray->alpha).z, 2) + pow((obj->pos).x, 2) +
    pow((obj->pos).y, 2) + pow((obj->pos).z, 2) - 2 *
    (((ray->alpha).x * (obj->pos).x) + ((ray->alpha).y * (obj->pos).y) +
     ((ray->alpha).z * (obj->pos).z)) - pow(obj->size, 2);
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
