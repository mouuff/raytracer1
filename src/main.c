/*
** main.c for main in /home/alies/rendu/gfx_wolf3d
**
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
**
** Started on  Wed Dec  2 20:18:06 2015 Arnaud Alies
** Last update Sat Feb 13 11:24:11 2016 alies_a
*/

#include <lapin.h>
#include "rt.h"

void	init_cam(t_cam *cam)
{
  cam->alpha = M_PI;
  cam->beta = 0;
  (cam->pos).x = 10;
  (cam->pos).y = 0;
  (cam->pos).z = 9;
}

int	init_obj(t_data *data)
{
  
  (data->light).x = 0;
  (data->light).y = 5;
  (data->light).z = 10.5;
  
  (data->objs).nb = 5;
  if (((data->objs).objs = malloc(sizeof(t_obj) * (data->objs).nb)) == NULL)
    return (1);
  
  ((data->objs).objs)[0].size = 4;
  ((data->objs).objs)[0].type = 'z';
  (((data->objs).objs)[0].pos).x = 0;
  (((data->objs).objs)[0].pos).y = 0;
  (((data->objs).objs)[0].pos).z = 0;
  (((data->objs).objs)[0].color).full = WHITE;
  
  ((data->objs).objs)[1].size = 4;
  ((data->objs).objs)[1].type = 's';
  (((data->objs).objs)[1].pos).x = 0;
  (((data->objs).objs)[1].pos).y = -4;
  (((data->objs).objs)[1].pos).z = 4;
  (((data->objs).objs)[1].color).full = RED;
  
  ((data->objs).objs)[2].size = 3;
  ((data->objs).objs)[2].type = 's';
  (((data->objs).objs)[2].pos).x = 0;
  (((data->objs).objs)[2].pos).y = 2;
  (((data->objs).objs)[2].pos).z = 4;
  (((data->objs).objs)[2].color).full = BLUE;
  
  ((data->objs).objs)[3].size = 1;
  ((data->objs).objs)[3].type = 'c';
  (((data->objs).objs)[3].pos).x = 2;
  (((data->objs).objs)[3].pos).y = 8;
  (((data->objs).objs)[3].pos).z = 8;
  (((data->objs).objs)[3].color).full = PINK;

  ((data->objs).objs)[4].size = 0.5;
  ((data->objs).objs)[4].type = 's';
  (((data->objs).objs)[4].pos).x = 0;
  (((data->objs).objs)[4].pos).y = 0;
  (((data->objs).objs)[4].pos).z = 0;
  (((data->objs).objs)[4].color).full = YELLOW;
  
  //(data->objs).nb = 3;
  return (0);
}

void	move(t_data *data)
{
  if (data->keys != NULL)
    {
      if (data->keys[BKS_UP])
	(data->cam).beta += 0.05;
      if (data->keys[BKS_DOWN])
	(data->cam).beta -= 0.05;
      if (data->keys[BKS_RIGHT])
	(data->cam).alpha -= 0.05;
      if (data->keys[BKS_LEFT])
	(data->cam).alpha += 0.05;
      if (data->keys[BKS_Q])
        {
	  //(((data->objs).objs)[1].pos).z += 0.1;
	  (data->light).x -= 0.2;
	}
      if (data->keys[BKS_D])
        {
	  //(((data->objs).objs)[1].pos).z += 0.1;
	  (data->light).x += 0.2;
	}
      if (data->keys[BKS_S])
        {
	  //(((data->objs).objs)[1].pos).z += 0.1;
	  (data->light).y -= 0.2;
	}
      if (data->keys[BKS_Z])
        {
	  //(((data->objs).objs)[1].pos).z += 0.1;
	  (data->light).y += 0.2;
	}
    }
  //printf("%f %f\n", (data->cam).alpha, (data->cam).beta);
}

t_bunny_response key_listenner(t_bunny_event_state state,
			       t_bunny_keysym keysym,
			       void *data_pt)
{
  t_data        *data;

  data = (t_data*)data_pt;
  data->keys = bunny_get_keyboard();
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

static t_bunny_response	loop(void *data_pt)
{
  t_data		*data;
  t_bunny_position      zero;

  zero.x = 0;
  zero.y = 0;
  data = (t_data*)data_pt;
  /*
  (((data->objs).objs)[4].pos).x = data->light.x;
  (((data->objs).objs)[4].pos).y = data->light.y;
  (((data->objs).objs)[4].pos).z = data->light.z;
  */
  move(data);
  display(data);
  bunny_blit(&((data->win)->buffer), &((data->pix)->clipable), &zero);
  bunny_display(data->win);
  return (GO_ON);
}

void	test()
{
  t_hit hit;
  t_ray ray;
  t_obj obj;

  obj.size = 4.5;
  (obj.pos).x = 0;
  (obj.pos).y = 0;
  (obj.pos).z = 0;
  
  (ray.alpha).x = 4;
  (ray.alpha).y = 0;
  (ray.alpha).z = 3;
  
  (ray.beta).x = 0;
  (ray.beta).y = 0;
  (ray.beta).z = -2;
  
  hit = sphere(&ray, &obj);
  printf("%f %f %f\n", (hit.hitpos).x, (hit.hitpos).y, (hit.hitpos).z);
  printf("%f\n", (hit.norm));
}

int		main(int ac, char **av)
{
  t_data	data;

  (void)ac;
  (void)av;
  data.keys = NULL;
  init_cam(&(data.cam));
  init_obj(&data);
  test();
  if ((data.pix = bunny_new_pixelarray(WIDTH, HEIGHT)) == NULL)
    return (1);
  if ((data.win = bunny_start(WIDTH, HEIGHT, false, "ray")) == NULL)
    return (1);
  bunny_set_loop_main_function(loop);
  bunny_set_key_response(&key_listenner);
  bunny_loop(data.win, FPS, (void*)(&data));
  return (0);
}
