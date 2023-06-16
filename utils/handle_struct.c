#include "../lem_in.h"

void init_struct_antFarm(t_antFarm *af)
{
  af->ants_amount = 0;
  af->start_room = NULL;
  af->end_room = NULL;
  af->rooms = NULL;
  af->tunnels = NULL;
}

void free_antFarm(t_antFarm *af)
{
  t_room *tmp1;
  t_tunnel *tmp2;

  free(af->start_room);
  free(af->end_room);
  tmp1 = af->rooms;
  while (af->rooms)
  {
    af->rooms = af->rooms->next;
    free(tmp1->name);
    free(tmp1->connections);
    free(tmp1);
    tmp1 = af->rooms;
  }
  tmp2 = af->tunnels;
  while (af->tunnels)
  {
    af->tunnels = af->tunnels->next;
    free(tmp2->room1);
    free(tmp2->room2);
    free(tmp2);
    tmp2 = af->tunnels;
  }
}

t_room *create_room(char *name, int pos_x, int pos_y)
{
  t_room *room;

  if (!(room = malloc(sizeof(t_room))))
    ft_malloc_error();
  room->name = name;
  room->pos_x = pos_x;
  room->pos_y = pos_y;
  room->next = NULL;
  room->connections = NULL;
  return room;
}

t_tunnel *create_tunnel(char *room1, char *room2)
{
  t_tunnel *tunnel;

  if (!(tunnel = malloc(sizeof(t_tunnel))))
    ft_malloc_error();
  tunnel->room1 = room1;
  tunnel->room2 = room2;
  tunnel->next = NULL;
  return tunnel;
}

void add_room(t_antFarm *af, t_room *room)
{
  t_room *iter;

  iter = af->rooms;
  if (!iter)
  {
    af->rooms = room;
    return ;
  }
  while (iter->next)
    iter = iter->next;
  iter->next = room;
}

void add_tunnel(t_antFarm *af, t_tunnel *tunnel)
{
  t_tunnel *iter;

  iter = af->tunnels;
  if (!iter)
  {
    af->tunnels = tunnel;
    return ;
  }
  while (iter->next)
    iter = iter->next;
  iter->next = tunnel;
}

t_room *get_room(t_antFarm *af, char *name)
{
  t_room *iter;

  iter = af->rooms;
  if (ft_strcmp(name, af->start_room->name))
    return af->start_room;
  if (ft_strcmp(name, af->end_room->name))
    return af->end_room;
  while (iter)
  {
    if (ft_strcmp(name, iter->name))
      return iter;
    iter = iter->next;
  }
  return NULL;
}

int room_amount(t_antFarm *af)
{
  t_room *iter;
  int amount;

  amount = 2;
  iter = af->rooms;
  while (iter)
  {
    amount++;
    iter = iter->next;
  }
  return amount;
}

void add_room_front_array(t_room **array, t_room *room)
{
  int i;
  t_room *tmp;
  t_room *tmp2;

  i = 0;
  if (!array[0])
  {
    array[0] = room;
    array[1] = NULL;
    return ;
  }
  tmp2 = array[0];
  array[0] = room;
  while (array[i])
  {
    tmp = array[i+1];
    array[i+1] = tmp2;
    tmp2 = tmp;
    i++;
  }
}

void add_room_end_array(t_room **array, t_room *room)
{
  int i;

  i = 0;
  if (!array[0])
  {
    array[0] = room;
    array[1] = NULL;
    return ;
  }
  while (array[i])
    i++;
  array[i] = room;
  array[i+1] = NULL;
}

void remove_room_front_array(t_room **array)
{
  int i;

  i = 0;
  if (!array[0])
    return ;
  while (array[i])
  {
    array[i] = array[i+1];
    i++;
  }
}

int room_in_array(t_room **array, t_room *room)
{
  int i;

  i = 0;
  while (array[i])
  {
    if (ft_strcmp(array[i]->name, room->name))
      return 1;
    i++;
  }
  return 0;
}
