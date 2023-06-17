#include "../lem_in.h"

static char **find_connections(t_antFarm *af, char *room)
{
  t_tunnel *iter;
  char **conns;

  conns = NULL;
  iter = af->tunnels;
  while (iter)
  {
    if (ft_strcmp(iter->room1, room)) {
      if (!(conns = add_end_ds(conns, iter->room2)))
        ft_malloc_error();
    } else if (ft_strcmp(iter->room2, room)) {
      if (!(conns = add_end_ds(conns, iter->room1)))
        ft_malloc_error();
    }
    iter = iter->next;
  }
  return conns;
}

static t_room **create_connections(t_antFarm *af, t_room *room)
{
  t_room **conn;
  char **conn_names;
  int i;

  i = 0;
  conn_names = find_connections(af, room->name);
  if (!(conn = malloc(sizeof(t_room *) * (ft_len_ds(conn_names) + 1))))
    ft_malloc_error();
  while (i < ft_len_ds(conn_names))
  {
    if (!(conn[i] = get_room(af, conn_names[i])))
      ft_error("lem-in: Error: Intern error room not found.\n");
    i++;
  }
  conn[i] = NULL;
  free_ds(conn_names);
  return conn;
}

static void create_graph(t_antFarm *af)
{
  t_room *iter;

  iter = af->rooms;
  af->start_room->connections = create_connections(af, af->start_room);
  af->end_room->connections = create_connections(af, af->end_room);
  while (iter)
  {
    iter->connections = create_connections(af, iter);
    iter = iter->next;
  }
}

static int double_room_coordinate(t_antFarm *af, int x, int y)
{
  t_room *iter;
  int occurence;

  occurence = 0;
  iter = af->rooms;
  if (af->start_room->pos_x == x && af->start_room->pos_y == y)
    occurence++;
  if (af->end_room->pos_x == x && af->end_room->pos_y == y)
    occurence++;
  while (iter)
  {
    if (iter->pos_x == x && iter->pos_y == y)
      occurence++;
    iter = iter->next;
  }
  return occurence > 1 ? 1 : 0;
}

static int double_room_name(t_antFarm *af, t_room *room)
{
  t_room *iter;
  int occurence;

  occurence = 0;
  iter = af->rooms;
  if (room == af->start_room)
    occurence++;
  if (room == af->end_room)
    occurence++;
  while (iter)
  {
    if (room == iter)
      occurence++;
    iter = iter->next;
  }
  return occurence > 1 ? 1 : 0;
}

static void room_verif(t_antFarm *af, t_room *iter1)
{
  //Verify no rooms with same name exist
  if (double_room_name(af, iter1))
    ft_error("lem-in: Error: Double room name.\n");
  //Verify no room's name start with L or are empty
  if (ft_strlen(iter1->name) < 1 || iter1->name[0] == 'L')
    ft_error("lem-in: Error: Invalid room name.\n");
  //Verify rooms have positive coordinates
  if (iter1->pos_x < 0 || iter1->pos_y < 0)
    ft_error("lem-in: Error: Invalid room coordinate.\n");
  //Verify no rooms are on same coordinate
  if (double_room_coordinate(af, iter1->pos_x, iter1->pos_y))
    ft_error("lem-in: Error: Double room coordinate.\n");
}

static void verify_antFarm(t_antFarm *af)
{
  t_room *iter1;
  t_tunnel *iter2;

  //Verify existence of start_room, end_room and at least one tunnel
  if (!af->start_room)
    ft_error("lem-in: Error: Missing starting room.\n");
  if (!af->end_room)
    ft_error("lem-in: Error: Missing end room.\n");
  if (!af->tunnels)
    ft_error("lem-in: Error: Missing tunnels.\n");
  room_verif(af, af->start_room);
  room_verif(af, af->end_room);
  iter1 = af->rooms;
  while (iter1)
  {
    room_verif(af, iter1);
    iter1 = iter1->next;
  }
  iter2 = af->tunnels;
  while (iter2)
  {
    //Verify all tunnels connect existing rooms
    if (!get_room(af, iter2->room1) || !get_room(af, iter2->room2))
        ft_error("lem-in: Error: Tunnel connects to non-existent room.\n");
    //Verify a tunnel does not connect between same room
    if (ft_strcmp(iter2->room1, iter2->room2))
      ft_error("lem-in: Error: Tunnel connects back to same room.\n");
    iter2 = iter2->next;
  }
}

static void verify_input_line(t_antFarm *af, char *line, char *status)
{
  char **split;

  if (ft_strlen(line) >= 1 && line[0] == '#'
        && !ft_strcmp(line, "##start") && !ft_strcmp(line, "##end")) //skip comment
    return ;
  else if (ft_strcmp(line, "##start"))
    ft_strlcpy(status, "start", ft_strlen("start") + 1);
  else if (ft_strcmp(line, "##end"))
    ft_strlcpy(status, "end", ft_strlen("end") + 1);
  else if (ft_strcmp(status, "ants")) //Take ant amount
  {
    if ((af->ants_amount = ft_atoi(line)) <= 0)
      ft_error("lem-in: Error: Invalid ants amount.\n");
    ft_strlcpy(status, "rooms", ft_strlen("rooms") + 1);
  } else if (ft_strcmp(status, "rooms") || ft_strcmp(status, "start") //Handle rooms
        || ft_strcmp(status, "end")) {
    if (!ft_strchr(line, ' ')) //If no space is to be found we know we are not handling rooms anymore but tunnels instead
    {
      ft_strlcpy(status, "tunnels", ft_strlen("tunnels") + 1);
      verify_input_line(af, line, status);
      return ;
    }
    if (!(split = ft_split(line, ' ')))
      ft_malloc_error();
    if (ft_len_ds(split) != 3)
      ft_error("lem-in: Error: Room description does not contain 3 values.\n");
    if (!ft_str_isdigit(split[1]) || !ft_str_isdigit(split[2]))
      ft_error("lem-in: Error: Room description coordinated are not numbers.\n");
    if (ft_strcmp(status, "rooms"))
        add_room(af, create_room(split[0], ft_atoi(split[1]), ft_atoi(split[2])));
    else if (ft_strcmp(status, "start"))
    {
      af->start_room = create_room(split[0], ft_atoi(split[1]), ft_atoi(split[2]));
      ft_strlcpy(status, "rooms", ft_strlen("rooms") + 1);
    }
    else
    {
      af->end_room = create_room(split[0], ft_atoi(split[1]), ft_atoi(split[2]));
      ft_strlcpy(status, "rooms", ft_strlen("rooms") + 1);
    }
    free(split[1]);
    free(split[2]);
  } else if (ft_strcmp(status, "tunnels")) { //Handle tunnels
    if (!(split = ft_split(line, '-')))
      ft_malloc_error();
    if (ft_len_ds(split) != 2)
      ft_error("lem-in: Error: Tunnel description does not contain 2 values.\n");
    add_tunnel(af, create_tunnel(split[0], split[1]));
  } else {
    ft_printf("lem-in: Error: Internal parsing error: status = %s.\n", status);
    exit(1);
  }
}

void parsing(t_antFarm *af)
{
  int ret;
  char *line;
  char status[10];

  ft_strlcpy(status, "ants", ft_strlen("ants") + 1);
  while ((ret = get_next_line(0, &line)))
  {
    if (ret == -1)
      ft_errno();
    verify_input_line(af, line, status);
    free(line);
  }
  verify_antFarm(af);
  create_graph(af);
}
