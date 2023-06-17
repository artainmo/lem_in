#include "../lem_in.h"

void display_results(t_room ***ant_path)
{
  if (!ant_path)
    return ;
  for (int l = 1; ant_path[path_array_len(ant_path)-1][l]; l++)
  {
    for (int i = 0; ant_path[i]; i++)
    {
      if (l < room_array_len(ant_path[i]) && ant_path[i][l] != ant_path[i][l-1])
        ft_printf("L%d-%s ", i+1, ant_path[i][l]->name);
    }
    ft_printf("\n");
  }
}

void view_path(t_room **path, int ant)
{
  int i;
  // char *conversion;

  i = 0;
  // if (!(conversion = ft_itoa(ant)))
  //   ft_malloc_error();
  // write(1, "Path Ant: ", 10);
  // write(1, conversion, ft_strlen(conversion));
  // write(1, "\n", 1);
  // free(conversion);
  printf("Path Ant: %d\n", ant); //My personal printf bugs... However bug is probably related not to printf itself but to prior code memory allocation problem...
  while (path && path[i])
  {
    if (path[i+1])
      ft_printf(" %s ->", path[i]->name);
    else
      ft_printf(" %s", path[i]->name);
    i++;
  }
  ft_printf("\n");
}

void display_paths(t_room ***ant_path)
{
  int i;

  i = 0;
  while (ant_path[i])
  {
    view_path(ant_path[i], i+1);
    i++;
  }
}

void view_stacks(t_room **queue, t_room **visited, t_room **origin)
{
  int i;

  i = 0;
  ft_printf("Visited:\n");
  while (visited && visited[i])
  {
    ft_printf("  %s:%s", origin[i]->name, visited[i]->name);
    i++;
  }
  ft_printf("\n");
  i = 0;
  ft_printf("Queue/Stack:\n");
  while (queue && queue[i])
  {
    ft_printf("  %s", queue[i]->name);
    i++;
  }
  ft_printf("\n");
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
