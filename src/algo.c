#include "../lem_in.h"

void go_to_end_room(t_room **queue, t_room **visited, char *end_room)
{
  int i;

  while (queue[0])
  {
    i = 0;
    while (queue[0]->connections[i])
    {
      // view_stacks(queue, visited);
      if (ft_strcmp(queue[0]->connections[i]->name, end_room))
        break ;
      if (!queue[0]->connections[i]->ants && //If the room is already filled with ant neglect it
            !room_in_array(visited, queue[0]->connections[i])) //If you already visited the room neglect it
      {
        if (!room_in_array(queue, queue[0]->connections[i]))
          add_room_end_array(queue, queue[0]->connections[i]);
        add_room_end_array(visited, queue[0]->connections[i]);
      }
      i++;
    }
    remove_room_front_array(queue);
  }
}

t_room *ant_move(t_antFarm *af, t_room *ant_room, int ant)
{
  t_room **visited;
  t_room **queue;

  if (!(visited = malloc(sizeof(t_room *) * room_amount(af) + 1)))
    ft_malloc_error();
  *visited = NULL;
  if (!(queue = malloc(sizeof(t_room *) * room_amount(af) + 1)))
    ft_malloc_error();
  *queue = NULL;
  add_room_end_array(visited, ant_room);
  add_room_end_array(queue, ant_room);
  go_to_end_room(queue, visited, af->end_room->name);
  exit(0);
  (void)ant;
  free(visited);
  free(queue);
}

void algo(t_antFarm *af)
{
  t_room **ant_room;
  t_room *old_room;

  if (!(ant_room = malloc(sizeof(t_room *) * af->ants_amount)))
    ft_malloc_error();
  for (int i = 0; i < af->ants_amount; i++) { ant_room[i] = af->start_room; }
  while (af->end_room->ants != af->ants_amount)
  {
    for (int ant = 1; ant <= af->ants_amount; ant++)
    {
      old_room = ant_room[ant-1];
      ant_room[ant-1] = ant_move(af, ant_room[ant-1], ant);
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
