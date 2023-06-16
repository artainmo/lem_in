#include "../lem_in.h"

void view_stacks(t_room **queue, t_room **visited)
{
  int i;

  i = 0;
  ft_printf("Visited:\n");
  while (visited[i])
  {
    ft_printf("  %s", visited[i]->name);
    i++;
  }
  ft_printf("\n");
  i = 0;
  ft_printf("Queue:\n");
  while (queue[i])
  {
    ft_printf("  %s", queue[i]->name);
    i++;
  }
  ft_printf("\n\n");
}


void view_parsed(t_antFarm *af)
{
  t_room *iter1;
  t_tunnel *iter2;

  ft_printf("%d\n", af->ants_amount);
  ft_printf("##start\n");
  ft_printf("%s %d %d\n", af->start_room->name, af->start_room->pos_x, af->start_room->pos_y);
  ft_printf("##end\n");
  ft_printf("%s %d %d\n", af->end_room->name, af->end_room->pos_x, af->end_room->pos_y);
  iter1 = af->rooms;
  while (iter1)
  {
    ft_printf("%s %d %d\n", iter1->name, iter1->pos_x, iter1->pos_y);
    iter1 = iter1->next;
  }
  iter2 = af->tunnels;
  while (iter2)
  {
    ft_printf("%s-%s\n", iter2->room1, iter2->room2);
    iter2 = iter2->next;
  }
  ft_printf("\n");
}

static void view_conns(t_room *room)
{
  int i;

  i = 0;
  ft_printf("%s:\n", room->name);
  while (room->connections[i])
  {
    ft_printf("  %s", room->connections[i]->name);
    i++;
  }
  ft_printf("\n");
}

void view_graph(t_antFarm *af)
{
  t_room *iter;

  iter = af->rooms;
  view_conns(af->start_room);
  while (iter)
  {
    view_conns(iter);
    iter = iter->next;
  }
  view_conns(af->end_room);
  ft_printf("\n");
}
