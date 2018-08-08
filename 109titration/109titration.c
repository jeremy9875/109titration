/*
** 109titration.c for 109titration in /home/VSridhar78/109titration
** 
** Made by Sridhar Vengadesan
** Login   <VSridhar78@epitech.net>
** 
** Started on  Wed Mar 29 08:25:46 2017 Sridhar Vengadesan
** Last update Thu Mar 30 15:08:16 2017 Sridhar Vengadesan
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	help(char *av)
{
  printf("USAGE\n\t%s file\n\nDESCRIPTION\n\tfile\ta csv containing", av);
  printf(" 'vol;ph' lines\n");
}

int	check_file(char *av)
{
  int	fd;
  int	i;
  char	buffer[200];

  i = 0;
  fd = open(av, O_RDONLY);
  if (fd == -1)
    {
      printf("Error opening file\n");
      return (84);
    }
  read(fd, buffer, 200);
  while (buffer[i] != '\0')
    {
      if (buffer[i] == ';' || buffer[i] == '.' || buffer[i] == '\n')
	i++;
      else if (buffer[i] >= 48 && buffer[i] <= 57)
	i++;
      else
	return (84);
    }
  return (0);
}

int	cmp_argv(char *av, int i)
{
  if (av[i] == '.')
    if (av[i + 1] == 'c')
      if (av[i + 2] == 's')
	if (av[i + 3] == 'v')
	  if (av[i + 4] == '\0')
	    return (0);
}

int	check_argv(char *av)
{
  int	i;

  i = 0;
  while (av[i] != '\0')
    {
      if (av[i] == '.')
	{
	  if (cmp_argv(av, i) == 0)
	    return (0);
	  else
	    return (84);
	}
      i++;
    }
  return (84);
}

int	main(int ac, char **av)
{
  if (ac == 2)
    {
      if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
	help(av[0]);
      else if (check_argv(av[1]) == 0)
	{
	  if (check_file(av[1]) == 0)
	    printf("OK\n");
	  else
	    return (84);
	}
      else
	return (84);
    }
  else
    return (84);
}
