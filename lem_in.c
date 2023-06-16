#include "lem_in.h"

int main(void)
{
  t_antFarm af;

  init_struct_antFarm(&af);
  parsing(&af);
  view_parsed(&af);
  view_graph(&af);
  algo(&af);
  free_antFarm(&af);
  return 0;
}
