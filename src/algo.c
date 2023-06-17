#include "../lem_in.h"

int g_ant; //Used for debugging

static int timing(t_room **visited, t_room **origin, t_room *final, t_room *start)
{
  int i;
  int _time;
  int occurence;
  t_room *search;

  _time = 0;
  if (final == start)
    return (room_array_len(visited) - 1);
  search = final;
  while (19)
  {
    i = 0;
    while (visited[i] && !ft_strcmp(visited[i]->name, search->name))
      i++;
    if (!visited[i] || !origin[i])
      ft_error("lem-in: Error: Internal error find shortest path.\n");
    occurence = room_occurence(visited, origin[i]);
    while (occurence) //If multiple instances follow of same room, you know he stayed in that round for multiple rounds
    {
      // ft_printf("OCC: %s:%s\n", origin[i]->name, visited[i]->name);
      _time++;
      occurence--;
    }
    if (ft_strcmp(origin[0]->name, origin[i]->name))
      break ;
    search = origin[i];
  }
  return _time;
}

static int ant_collision(t_room *next_room, t_room ***prior_ants_paths,
      t_room **visited, t_room **origin, t_room *mother_room, t_antFarm *af)
{
  int _time;

  if (!prior_ants_paths || !prior_ants_paths[0])
    return 0;
  _time = timing(visited, origin, mother_room, af->start_room);
  // if (g_ant == 3)
  // {
  //   ft_printf("\nROOM: %s:%s\nTIMING: %d\n", mother_room->name, next_room->name, _time);
  //   view_stacks(NULL, visited, origin);
  //   // ft_printf("Time: %d\n", _time);
  //   // display_paths(prior_ants_paths);
  // }
  for (int i = 0; prior_ants_paths[i] ; i++)
  {
    // if (g_ant == 3)
    //   ft_printf("COLLISION? %s|%s\n", prior_ants_paths[i][_time]->name, next_room->name);
    if (prior_ants_paths[i][_time+1] == next_room)
      return 1;
  }
  return 0;
}

static void shortest_path(t_room **visited, t_room **origin, t_room *final, t_room **path)
{
  int i;
  t_room *search;
  int occurence;

  search = final;
  add_room_front_array(path, final);
  while (19)
  {
    i = 0;
    while (visited[i] && !ft_strcmp(visited[i]->name, search->name))
      i++;
    // ft_printf("O %s:%s\n", origin[i]->name, visited[i]->name);
    if (!visited[i] || !origin[i])
      ft_error("lem-in: Error: Internal error find shortest path.\n");
    occurence = room_occurence(visited, origin[i]);
    while (occurence)
    {
      // ft_printf("I %s:%s\n", origin[i]->name, visited[i]->name);
      add_room_front_array(path, origin[i]);
      occurence--;
    }
    if (ft_strcmp(origin[0]->name, origin[i]->name)) //If we arrive to starting room we know the next room
      break ;
    search = origin[i];
  }
}

static t_room **ant_move(t_antFarm *af, t_room *ant_room,
      t_room ***prior_ants_paths) //Here we use the "Breadth First Search" algorithm
{
  t_room **visited;
  t_room **origin;
  t_room **queue;
  t_room **path;
  t_room *current;
  int i;

  if (!(visited = malloc(sizeof(t_room *) * (room_amount(af) + 3) * af->ants_amount)))
    ft_malloc_error();
  *visited = NULL;
  if (!(queue = malloc(sizeof(t_room *) * (room_amount(af) + 3) * af->ants_amount)))
    ft_malloc_error();
  *queue = NULL;
  if (!(origin = malloc(sizeof(t_room *) * (room_amount(af) + 3) * af->ants_amount)))
    ft_malloc_error();
  *origin = NULL;
  if (!(path = malloc(sizeof(t_room *) * (room_amount(af) + 3) * af->ants_amount)))
    ft_malloc_error();
  for (int l = 0; l <= room_amount(af) + 1; l++) { path[l] = NULL; }
  add_room_end_array(origin, ant_room);
  add_room_end_array(visited, ant_room);
  add_room_end_array(queue, ant_room);
  while (19)
  {
    if (!queue[0])
    {
      if (!prior_ants_paths[0])
        break ;
      //If you are blocked due to the other ants, stay in same room
      current = visited[room_array_len(visited)-1];
      add_room_end_array(queue, current);
      add_room_end_array(origin, current);
      add_room_end_array(visited, current);
    }
    i = 0;
    // if (g_ant == 3)
    //   view_stacks(queue, visited, origin);
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
        add_room_end_array(path, af->end_room);
        // view_path(path, 1);
        // exit(0);
        free(visited);
        free(origin);
        free(queue);
        return path;
      }
      if (room_in_array(visited, queue[0]->connections[i]) || //If you already visited the room neglect it
            ant_collision(queue[0]->connections[i], prior_ants_paths, //If the room is already filled with ant neglect it
            visited, origin, queue[0], af)) {
        i++;
        continue;
      } else {
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
  // if (!ant_move(af, af->start_room, ant_path))
  //   ft_error("lem-in: Error: Start and end room are not linked.\n");
  for (int ant = 1; ant <= af->ants_amount; ant++)
  {
      g_ant = ant;
      if (!(ant_path[ant-1] = ant_move(af, af->start_room, ant_path)))
        ft_error("lem-in: Error: Start and end room are not linked.\n");
      ant_path[ant] = NULL;
  }
  display_paths(ant_path);
  for (int i = 0; i < af->ants_amount; i++) { free(ant_path[i]); }
  free(ant_path);
}
