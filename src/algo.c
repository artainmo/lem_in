#include "../lem_in.h"

static void shortest_path(t_room **visited, t_room **origin, t_room *final, t_room **path)
{
  int i;
  t_room *search;

  search = final;
  add_room_front_array(path, final);
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
    add_room_front_array(path, origin[i]);
  }
}

static t_room **ant_move(t_antFarm *af, t_room *ant_room,
      t_room ***prior_ants_paths) //Here we use the "Breadth First Search" algorithm
{
  t_room **visited;
  t_room **origin;
  t_room **queue;
  t_room **path;
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
  if (!(path = malloc(sizeof(t_room *) * room_amount(af) + 1)))
    ft_malloc_error();
  *path = NULL;
  add_room_end_array(origin, ant_room);
  add_room_end_array(visited, ant_room);
  add_room_end_array(queue, ant_room);
  while (queue[0])
  {
    i = 0;
    view_stacks(queue, visited, origin);
    while (queue[0]->connections[i])
    {
      if (ft_strcmp(queue[0]->connections[i]->name, af->end_room->name))
      {
        if (queue[0] == ant_room) {
          path[0] = ant_room;
          path[1] = af->end_room;
          path[2] = NULL;
          // view_path(path, 1);
          // exit(0);
          free(visited);
          free(origin);
          free(queue);
          return path;
        }
        shortest_path(visited, origin, queue[0], path);
        add_room_front_array(path, af->start_room);
        add_room_end_array(path, af->end_room);
        // view_path(path, 1);
        // exit(0);
        free(visited);
        free(origin);
        free(queue);
        return path;
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
  free(path);
  return NULL;
}

void algo(t_antFarm *af)
{
  t_room ***ant_path;

  if (!(ant_path = malloc(sizeof(t_room *) * af->ants_amount)))
    ft_malloc_error();
  ant_path[0] = NULL;
  if (!ant_move(af, af->start_room, ant_path))
    ft_error("lem-in: Error: Start and end room are not linked.\n");
  for (int ant = 1; ant <= af->ants_amount; ant++)
      ant_path[ant-1] = ant_move(af, af->start_room, ant_path);
  display_paths(ant_path, af->ants_amount);
  for (int i = 0; i < af->ants_amount; i++) { free(ant_path[i]); }
  free(ant_path);
}
