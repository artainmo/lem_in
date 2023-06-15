#include "../lem_in.h"

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
