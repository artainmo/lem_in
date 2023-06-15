#ifndef LEM_IN_H
#define LEM_IN_H

#include "utils/libft/libft.h"
#include "utils/get_next_line/get_next_line.h"
#include "utils/ft_printf/printf.h"

typedef struct s_room
{
  char *name;
  int pos_x;
  int pos_y;
  struct s_room *next;
} t_room;

typedef struct s_tunnel
{
  char *room1;
  char *room2;
  struct s_tunnel *next;
} t_tunnel;

typedef struct s_antFarm
{
  int ants_amount;
  t_room *start_room;
  t_room *end_room;
  t_room *rooms;
  t_tunnel *tunnels;
} t_antFarm;

void init_struct_antFarm(t_antFarm *af);
t_room *create_room(char *name, int pos_x, int pos_y);
t_tunnel *create_tunnel(char *room1, char *room2);
void add_room(t_antFarm *af, t_room *room);
void add_tunnel(t_antFarm *af, t_tunnel *tunnel);
t_room *get_room(t_antFarm *af, char *name);
void free_antFarm(t_antFarm *af);

void parsing(t_antFarm *af);
void view_parsed(t_antFarm *af);

#endif
