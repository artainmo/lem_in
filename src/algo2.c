#include "../lem_in.h"

static t_room **find_shortest_path(t_room ***all_distinct_paths, int *len)
{
  int i;
  t_room **path;

  i = 0;
  path = NULL;
  while (len[i+1])
  {
    if (len[i] < len[i+1])
    {
      path = path_cpy(all_distinct_paths[i]);
      add_room_front_array(all_distinct_paths[i], all_distinct_paths[i][0]);
      len[i] += 1;
      return path;
    }
    i++;
  }
  path = path_cpy(all_distinct_paths[i]);
  add_room_front_array(all_distinct_paths[i], all_distinct_paths[i][0]);
  len[i] += 1;
  return path;
}

static void shortest_path(t_room **visited, t_room **origin, t_room *final, t_room **path)
{
  int i;
  t_room *search;

  search = final;
  add_room_front_array(path, final);
  while (origin[0] != search)
  {
    i = 0;
    while (visited[i] != search)
      i++;
    add_room_front_array(path, origin[i]);
    search = origin[i];
  }
}

static t_room **find_distinct_path(t_antFarm *af, int max_potential_moves)
{
  t_room **visited;
  t_room **origin;
  t_room **queue;
  t_room **path;

  if (!(visited = malloc(sizeof(t_room) * max_potential_moves)))
    ft_malloc_error();
  *visited = NULL;
  if (!(queue = malloc(sizeof(t_room) * max_potential_moves)))
    ft_malloc_error();
  *queue = NULL;
  if (!(origin = malloc(sizeof(t_room) * max_potential_moves)))
    ft_malloc_error();
  *origin = NULL;
  if (!(path = malloc(sizeof(t_room) * max_potential_moves)))
    ft_malloc_error();
  *path = NULL;
  add_room_end_array(origin, af->start_room);
  add_room_end_array(visited, af->start_room);
  add_room_end_array(queue, af->start_room);
  while (queue[0])
  {
    for (int i = 0; queue[0]->connections[i]; i++)
    {
      if (queue[0]->connections[i] == af->end_room)
      {
        shortest_path(visited, origin, queue[0], path);
        add_room_end_array(path, af->end_room);
        free(visited);
        free(queue);
        free(origin);
        return path;
      } else if (!queue[0]->connections[i]->locked) {
        add_room_end_array(queue, queue[0]->connections[i]);
        add_room_end_array(origin, queue[0]);
        add_room_end_array(visited, queue[0]->connections[i]);
        queue[0]->connections[i]->locked = 1;
      }
    }
    remove_room_front_array(queue);
  }
  free(visited);
  free(queue);
  free(origin);
  free(path);
  return NULL;
}

static void find_all_distinct_paths(t_antFarm *af,
        t_room ***all_distinct_paths, int *len, int max_potential_moves)
{
  int i;

  i = 0;
  while ((all_distinct_paths[i] = find_distinct_path(af, max_potential_moves)))
  {
    len[i] = room_array_len(all_distinct_paths[i]);
    i++;
    all_distinct_paths[i] = NULL;
    len[i] = 0;
    unlock_all_rooms(af->rooms);
    lock_paths(all_distinct_paths);
  }
}

void algo2(t_antFarm *af, int visu_mode, int quiet_mode)
{
  t_room ***ant_path;
  t_room ***all_distinct_paths;
  int *len;
  int max_potential_moves;

  max_potential_moves = ((room_amount(af) + 3) * af->ants_amount) + 1;
  if (!(ant_path = malloc(sizeof(t_room *) * af->ants_amount)))
    ft_malloc_error();
  ant_path[0] = NULL;
  if (!(all_distinct_paths = malloc(sizeof(t_room *) * max_potential_moves)))
    ft_malloc_error();
  all_distinct_paths[0] = NULL;
  if (!(len = malloc(sizeof(int) * max_potential_moves)))
    ft_malloc_error();
  len[0] = 0;
  find_all_distinct_paths(af, all_distinct_paths, len, max_potential_moves);
  if (!all_distinct_paths[0])
    ft_error("lem-in: Error: Start and end room are not linked.\n");
  for (int ant = 0; ant < af->ants_amount; ant++) {
      ant_path[ant] = find_shortest_path(all_distinct_paths, len);
      ant_path[ant+1] = NULL;
  }
  if (quiet_mode != 2 && !visu_mode)
    display_results(ant_path);
  else if (quiet_mode != 2 && visu_mode == 2)
    display_paths(ant_path);
  else if (quiet_mode != 2)
    visualize_graph(af, ant_path);
  for (int i = 0; i < af->ants_amount; i++) { free(ant_path[i]); }
  free(ant_path);
  for (int i = 0; all_distinct_paths[i]; i++) { free(all_distinct_paths[i]); }
  free(all_distinct_paths);
}
