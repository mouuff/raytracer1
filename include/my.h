/*
** my.h for wolf in /home/alies/rendu/gfx_wolf3d
** 
** Made by Arnaud Alies
** Login   <alies_a@epitech.net>
** 
** Started on  Fri Dec 11 21:01:39 2015 Arnaud Alies
** Last update Mon Mar  7 13:10:25 2016 alies_a
*/

#ifndef MY_H_
#define MY_H_

#include <stddef.h>

int     my_putchar(char c);
int     my_putstr(const char *str);
char    *my_strcat(char *dest, char *src);
char    *my_strdup(const char *src);
int     my_strlen(const char *str);
int     my_str_to_nbr(const char *str);
void	my_memset(void *s, char c, size_t n);
char    *my_strcpy(char *dest, const char *src);

#endif
