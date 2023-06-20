#include "../lem_in.h"

int g_ant; //Used for debugging

static int timing(t_room **visited, t_room **origin, t_room *final, t_room *start)
{
  int i;
  int _time;
  t_room *search;
  int occurence;

  _time = 0;
  (void)start;
  if (final == visited[0])
    return room_occurence(visited, final) - 1;
  search = final;
  while (19)
  {
    i = 0;
    while (visited[i] && visited[i] != search)
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
    if (origin[0] == origin[i])
      break ;
    search = origin[i];
  }
  return _time;
}

static void shortest_path(t_room **visited, t_room **origin, t_room *final, t_room **path)
{
  int i;
  t_room *search;
  int occurence;

  if (final == visited[0]) {
    // view_stacks(NULL, visited, origin);
    occurence = room_occurence(visited, final);
    while (occurence--)
      add_room_front_array(path, final);
    return ;
  }
  search = final;
  add_room_front_array(path, final);
  while (19)
  {
    i = 0;
    while (visited[i] && visited[i] != search)
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
    if (origin[0] == origin[i]) //If we arrive to starting room we know the next room
      break ;
    search = origin[i];
  }
}

static int ant_collision(t_room *next_room, t_room ***prior_ants_paths,
      t_room **visited, t_room **origin, t_room *mother_room, t_antFarm *af,
      t_room ***alternative_paths, int max_potential_moves)
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
    if (prior_ants_paths[i][_time+1] == next_room) //Create alternative path if ant collision occurs
    {
      int len = path_array_len(alternative_paths);
      if (!(alternative_paths[len] = malloc(sizeof(t_room *) * max_potential_moves)))
        ft_malloc_error();
      alternative_paths[len][0] = NULL;
      alternative_paths[len+1] = NULL;
      // ft_printf("ANT:%d\n", g_ant);
      // view_path(alternative_paths[len], -1);
      shortest_path(visited, origin, mother_room, alternative_paths[len]);
      // view_path(alternative_paths[len], 0);
      int it = _time+1;
      for (int l = i; prior_ants_paths[l]; l++) { //Add multiple waits if on next rounds other ants already are about to use next_room
        // view_path(prior_ants_paths[l], -3);
        // ft_printf("%s:%s\n", prior_ants_paths[l][it]->name, next_room->name);
        if (prior_ants_paths[l][it-1] && prior_ants_paths[l][it] == next_room)
        {
          add_room_end_array(alternative_paths[len], mother_room);
          it++;
        }
      }
      // view_path(alternative_paths[len], 1);
      for (int t = _time+1; prior_ants_paths[i][t]; t++) {
        add_room_end_array(alternative_paths[len], prior_ants_paths[i][t]);
      }
      // view_path(alternative_paths[len], 2);
      // ft_printf("ANT: %d\n", g_ant);
      // display_paths(alternative_paths);
      // write(1,"\n",1);
      return 1;
    }
  }
  return 0;
}

static t_room **choose_path(t_room **path, t_room ***alternative_paths)
{
  int len;
  int len2;
  t_room **chosen_path;

  // ft_printf("ANT: %d\n", g_ant);
  // display_paths(alternative_paths);
  // return path;
  if (!alternative_paths)
    return path;
  len = room_array_len(path);
  chosen_path = path;
  // ft_printf("ANT: %d | LEN: %d\n", g_ant, len);
  for (int i = 0; alternative_paths[i]; i++) {
    len2 = room_array_len(alternative_paths[i]);
    if (!chosen_path || len > len2)
    {
      // ft_printf("ANT: %d | LEN: %d\n", g_ant, len2);
      len = len2;
      chosen_path = alternative_paths[i];
    }
  }
  if (path && path != chosen_path)
    free(path);
  free(alternative_paths);
  // view_path(chosen_path, -10);
  // // if (g_ant == 6)
  // //   exit(0);
  // ft_printf("%s\n", chosen_path[0]->name);
  return chosen_path;
}

static t_room **ant_move(t_antFarm *af, t_room *ant_room,
      t_room ***prior_ants_paths) //Here we use the "Breadth First Search" algorithm
{
  t_room **visited;
  t_room **origin;
  t_room **queue;
  t_room **path;
  t_room ***alternative_paths;
  t_room *current;
  int i;
  int max_potential_moves;

  max_potential_moves = ((room_amount(af) + 3) * af->ants_amount) + 1;
  if (!(visited = malloc(sizeof(t_room *) * max_potential_moves)))
    ft_malloc_error();
  *visited = NULL;
  if (!(queue = malloc(sizeof(t_room *) * max_potential_moves)))
    ft_malloc_error();
  *queue = NULL;
  if (!(origin = malloc(sizeof(t_room *) * max_potential_moves)))
    ft_malloc_error();
  *origin = NULL;
  if (!(path = malloc(sizeof(t_room *) * max_potential_moves)))
    ft_malloc_error();
  for (int l = 0; l < max_potential_moves; l++) { path[l] = NULL; }
  if (!(alternative_paths = malloc(sizeof(t_room **) * max_potential_moves)))
    ft_malloc_error();
  alternative_paths[0] = NULL;
  add_room_end_array(origin, ant_room);
  add_room_end_array(visited, ant_room);
  add_room_end_array(queue, ant_room);
  while (19)
  {
    // ft_printf("Current Ant: %d\n", g_ant);
    // display_paths(prior_ants_paths);
    // if (g_ant == 16) exit(0);
    if (!queue[0])
    {
      if (!prior_ants_paths[0])
        break ;
      current = visited[room_array_len(visited)-1];
      if (current != af->start_room && room_array_len(current->connections) <= 1) //If the room has only one connection and is not the starting room you know this sole connection is the one behind him and because we won't go backwards he is stuck and thus we give him an alternative path
      {
        free(visited);
        free(origin);
        free(queue);
        return choose_path(NULL, alternative_paths);
      }
      //If you are blocked due to the other ants, stay in same room
      add_room_end_array(queue, current);
      add_room_end_array(origin, current);
      add_room_end_array(visited, current);
    }
    i = 0;
    // if (g_ant == 3)
    //   view_stacks(queue, visited, origin);
    while (queue[0]->connections[i])
    {
      if (queue[0]->connections[i] == af->end_room)
      {
        if (queue[0] == ant_room) {
          path[0] = ant_room;
          path[1] = af->end_room;
          path[2] = NULL;
          // view_path(path, 1);
          // exit(0);
          write(1,"s\n",2);
          free(visited);
          free(origin);
          free(queue);
          return path;
        }
        shortest_path(visited, origin, queue[0], path);
        add_room_end_array(path, af->end_room);
        // view_path(path, 1);
        // exit(0);
        write(1,"r\n",2);
        free(visited);
        free(origin);
        free(queue);
        write(1,"r1\n",3);
        return choose_path(path, alternative_paths);
      }
      if (room_in_array(visited, queue[0]->connections[i]) || //If you already visited the room neglect it
            ant_collision(queue[0]->connections[i], prior_ants_paths, //If the room is already filled with ant, create alternative path
                  visited, origin, queue[0], af, alternative_paths,
                  max_potential_moves)) {
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
  write(1,"h\n",2);
  free(visited);
  free(origin);
  free(queue);
  free(path);
  return NULL;
}

t_room ***algo(t_antFarm *af, int visu_mode)
{
  t_room ***ant_path;

  if (!(ant_path = malloc(sizeof(t_room **) * af->ants_amount)))
    ft_malloc_error();
  ant_path[0] = NULL;
  // if (!ant_move(af, af->start_room, ant_path))
  //   ft_error("lem-in: Error: Start and end room are not linked.\n");
  for (int ant = 1; ant <= af->ants_amount; ant++)
  {
      g_ant = ant;
      if (!(ant_path[ant-1] = ant_move(af, af->start_room, ant_path)))
        ft_error("lem-in: Error: Start and end room are not linked.\n");
      write(1,"e1\n",3);
      ant_path[ant] = NULL;
  }
  if (!visu_mode)
    display_results(ant_path);
  else if (visu_mode == 2)
    display_paths(ant_path);
  else
    visualize_graph(af, ant_path);
  write(1,"e2\n",3);
  for (int i = 0; i < af->ants_amount; i++) { free(ant_path[i]); }
  free(ant_path);
  return ant_path;
}
