#include "lem_in.h"

int main(int argc, char **argv)
{
  t_antFarm af;
  int quit_mode;

  quit_mode = 0;
  if (argc > 1 && ft_strcmp(argv[1], "-q"))
    quit_mode = 1;
  init_struct_antFarm(&af);
  parsing(&af, quit_mode);
  // view_parsed(&af);
  // view_graph(&af);
  algo(&af);
  free_antFarm(&af);
  return 0;
}
