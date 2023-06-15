#include "../lem_in.h"

static void verify_antFarm(t_antFarm *af)
{
  (void)af;
  //Verify existence of start_room, end_room and at least one tunnel
  //Verify no rooms with same name exist
  //Verify no room's name start with L
  //Verify rooms have positive coordinates
  //Verify no rooms are on same coordinate
  //Verify all tunnels connect existing rooms
  //Verify all tunnels do not connect to same room
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
}
