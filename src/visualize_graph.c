#include "../lem_in.h"

typedef struct s_point {
    int x;
    int y;
} t_point;

void show_tunnels(t_point ***tunnels)
{
  for (int i = 0; tunnels[i]; i++) {
    for (int l = 0; tunnels[i][l]; l++) {
      ft_printf("TUNNEL %d: %d %d\n", i, tunnels[i][l]->x, tunnels[i][l]->y);
    }
    write(1,"\n",1);
  }
}

int coordinate_of_one_tunnel(int x1, int y1, t_point ***tunnels)
{
  for (int i = 0; tunnels[i]; i++) {
    for (int l = 0; tunnels[i][l]; l++) {
      if (tunnels[i][l]->x == x1 && tunnels[i][l]->y == y1)
        return 1;
    }
  }
  return 0;
}

t_point **tunnel_coordinates(float x1, float y1, float x2, float y2)
{
  float number_of_points;
  t_point **tunnel;
  float x_increment;
  float y_increment;
  float x;
  float y;

  // ft_printf("%f %f | %f %f\n", x1, y1, x2, y2);
  number_of_points = ft_abs(x2 - x1) + ft_abs(y2 - y1);
  // ft_printf("%f\n", number_of_points);
  if (!(tunnel = malloc(sizeof(t_point *) * number_of_points + 1)))
    ft_malloc_error();
  x_increment = (x2 - x1) / number_of_points;
  y_increment = (y2 - y1) / number_of_points;
  x = x1 + x_increment;
  y = y1 + y_increment;
  // ft_printf("INCREMENT %f %f\n", x_increment, y_increment);
  for (int i = 0; i < number_of_points; i++) {
        if (!(tunnel[i] = malloc(sizeof(t_point))))
          ft_malloc_error();
        tunnel[i]->x = (int)x;
        tunnel[i]->y = (int)y;
        // ft_printf("tunnel %d: %d %d\n", i, tunnel[i]->x, tunnel[i]->y);
        x += x_increment;
        y += y_increment;
  }
  tunnel[(int)number_of_points] = NULL;
  return tunnel;
}

t_point ***get_tunnels(t_antFarm *af)
{
  t_point ***tunnels;
  t_tunnel *iter;
  int i;

  if (!(tunnels = malloc(sizeof(t_point *) * tunnel_amount(af) + 1)))
    ft_malloc_error();
  iter = af->tunnels;
  i = 0;
  while (iter)
  {
    tunnels[i] = tunnel_coordinates(get_room(af, iter->room1)->pos_x,
          get_room(af, iter->room1)->pos_y, get_room(af, iter->room2)->pos_x,
          get_room(af, iter->room2)->pos_y);
    // for (int l = 0; tunnels[i][l]; l++) {
    //   ft_printf("%d: %d %d\n", i, tunnels[i][l]->x, tunnels[i][l]->y);
    // }
    // write(1,"\n",1);
    iter = iter->next;
    i++;
  }
  tunnels[i] = NULL;
  return tunnels;
}

int ant_in_room(t_room ***ant_path, int x, int y, int t, t_antFarm *af)
{
  for (int i = 0; i < af->ants_amount; i++)
  {
    if (t < room_array_len(ant_path[i]) && ant_path[i][t]->pos_x == x && ant_path[i][t]->pos_y == y)
    {
      return 1;
    }
  }
  return 0;
}

int find_max_y(t_room *start, t_room *end, t_room *rooms)
{
  t_room *iter;
  int max_y;

  max_y = start->pos_y;
  iter = rooms;
  while (iter)
  {
    if (iter->pos_y > max_y)
      max_y = iter->pos_y;
    iter = iter->next;
  }
  if (end->pos_y > max_y)
    max_y = end->pos_y;
  if (max_y < 10)
    return max_y + 1;
  return max_y + (max_y/10);
}

int find_max_x(t_room *start, t_room *end, t_room *rooms)
{
  t_room *iter;
  int max_x;

  max_x = start->pos_x;
  iter = rooms;
  while (iter)
  {
    // ft_printf("SEARCH MAX x: %d\n", rooms->pos_x);
    if (iter->pos_x > max_x)
      max_x = iter->pos_x;
    iter = iter->next;
  }
  if (end->pos_x > max_x)
    max_x = end->pos_x;
  if (max_x < 10)
    return max_x + 1;
  return max_x + (max_x/10);
}

int coordinate_of_one_room(t_room *start, t_room *end, t_room *rooms, int x, int y)
{
  t_room *iter;

  if (start->pos_x == x && start->pos_y == y)
    return 1; //Return 1 for starting room
  iter = rooms;
  while (iter)
  {
    if (iter->pos_x == x && iter->pos_y == y)
      return 2; //Return 2 for in-between rooms
    iter = iter->next;
  }
  if (end->pos_x == x && end->pos_y == y)
    return 3; //Return 3 for end-room
  return 0;
}

void visualize_graph(t_antFarm *af, t_room ***ant_path)
{
  int x;
  int y;
  int max_x;
  int max_y;
  int ret;
  t_point ***tunnels;

  max_x = find_max_x(af->start_room, af->end_room, af->rooms);
  max_y = find_max_y(af->start_room, af->end_room, af->rooms);
  tunnels = get_tunnels(af);
  // show_tunnels(tunnels);
  // exit(0);
  // ft_printf("MAX: %d %d\n", max_x, max_y);
  for (int t = 0; ant_path[af->ants_amount-1][t]; t++) {
    y = 0;
    x = 0;
    while (y != max_y)
    {
      // ft_printf("%d %d\n", x, y);
      if (x == max_x)
      {
        x = -1;
        y++;
        write(1,"\n",1);
      } else if ((ret = coordinate_of_one_room(
              af->start_room, af->end_room, af->rooms, x, y))) {
        if (ret == 1)
          write(1,"s",1);
        else if (ret == 3)
          write(1,"e",1);
        else if (ret == 2) {
          if (ant_in_room(ant_path, x, y, t, af))
            write(1,"a",1);
          else
            write(1,"r",1);
        }
      } else if (coordinate_of_one_tunnel(x, y, tunnels)) {
        write(1,"-",1);
      } else {
        write(1," ",1);
      }
      x++;
    }
    write(1,"\n",1);
    sleep(3);
  }
  for (int i = 0; tunnels[i]; i++) {
    for (int l = 0; tunnels[i][l]; l++) {
      free(tunnels[i][l]);
    }
    free(tunnels[i]);
  }
  free(tunnels);
}
