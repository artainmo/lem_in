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
  struct s_room *next; //Linked list
  struct s_room **connections; //To create a graph. Represents connections between rooms by tunnels.
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
int room_amount(t_antFarm *af);
void add_room_front_array(t_room **array, t_room *room);
void add_room_end_array(t_room **array, t_room *room);
void remove_room_front_array(t_room **array);
int room_in_array(t_room **array, t_room *room);
int room_array_len(t_room **rooms);
int path_array_len(t_room ***paths);
int room_occurence(t_room **rooms, t_room *room);

void parsing(t_antFarm *af);

void view_parsed(t_antFarm *af);
void view_graph(t_antFarm *af);
void view_stacks(t_room **queue, t_room **visited, t_room **origin);
void view_path(t_room **path, int ant);
void display_paths(t_room ***ant_path);
void display_results(t_room ***ant_path);

void algo(t_antFarm *af);

#endif
