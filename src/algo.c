#include "../lem_in.h"

static t_room *shortest_path_next_room(t_room **visited, t_room **origin, t_room *final)
{
  int i;
  t_room *search;

  search = final;
  while (19)
  {
    i = 0;
    while (visited[i] && !ft_strcmp(visited[i]->name, search->name))
      i++;
    // ft_printf("%s:%s\n", origin[i]->name, visited[i]->name);
    if (!visited[i] || !origin[i])
      ft_error("lem-in: Error: Internal error find shortest path.\n");
    if (ft_strcmp(origin[0]->name, origin[i]->name)) //If we arrive to starting room we know the next room
      break ;
    search = origin[i];
  }
  return search;
}

static t_room *ant_move(t_antFarm *af, t_room *ant_room) //Here we use the "Breadth First Search" algorithm
{
  t_room **visited;
  t_room **origin;
  t_room **queue;
  t_room *next_room;
  int i;

  if (!(visited = malloc(sizeof(t_room *) * room_amount(af) + 1)))
    ft_malloc_error();
  *visited = NULL;
  if (!(queue = malloc(sizeof(t_room *) * room_amount(af) + 1)))
    ft_malloc_error();
  *queue = NULL;
  if (!(origin = malloc(sizeof(t_room *) * room_amount(af) + 1)))
    ft_malloc_error();
  *origin = NULL;
  add_room_end_array(origin, ant_room);
  add_room_end_array(visited, ant_room);
  add_room_end_array(queue, ant_room);
  while (queue[0])
  {
    i = 0;
    // view_stacks(queue, visited, origin);
    while (queue[0]->connections[i])
    {
      if (ft_strcmp(queue[0]->connections[i]->name, af->end_room->name))
      {
        if (queue[0] == ant_room) return af->end_room;
        next_room = shortest_path_next_room(visited, origin, queue[0]);
        free(visited);
        free(origin);
        free(queue);
        return next_room;
      }
      if (!queue[0]->connections[i]->ants && //If the room is already filled with ant neglect it
            !room_in_array(visited, queue[0]->connections[i])) //If you already visited the room neglect it
      {
        add_room_end_array(queue, queue[0]->connections[i]);
        add_room_end_array(origin, queue[0]);
        add_room_end_array(visited, queue[0]->connections[i]);
      }
      i++;
    }
    remove_room_front_array(queue);
  }
  free(visited);
  free(origin);
  free(queue);
  return ant_room;
}

void algo(t_antFarm *af)
{
  t_room **ant_room;
  t_room *old_room;

  if (ant_move(af, af->start_room) == af->start_room)
    ft_error("lem-in: Error: Start and end room are not linked.\n");
  if (!(ant_room = malloc(sizeof(t_room *) * af->ants_amount)))
    ft_malloc_error();
  for (int i = 0; i < af->ants_amount; i++) { ant_room[i] = af->start_room; }
  while (af->end_room->ants != af->ants_amount)
  {
    for (int ant = 1; ant <= af->ants_amount; ant++)
    {
      old_room = ant_room[ant-1];
      ant_room[ant-1] = ant_move(af, ant_room[ant-1]);
      if (!ft_strcmp(old_room->name, ant_room[ant-1]->name))
      {
        old_room->ants = 0;
        ant_room[ant-1]->ants = ant;
        ft_printf("L%d-%s ", ant, ant_room[ant-1]->name);
      }
    }
    ft_printf("\n");
  }
  free(ant_room);
}
