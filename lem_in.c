#include "lem_in.h"

int main(int argc, char **argv)
{
  t_antFarm af;
  int quit_mode;
  int visu_mode;

  quit_mode = 0;
  visu_mode = 0;
  if (argc > 1 && ft_strcmp(argv[1], "-q"))
    quit_mode = 1;
  else if (argc > 1 && ft_strcmp(argv[1], "-v"))
    visu_mode = 1;
  else if (argc > 1 && ft_strcmp(argv[1], "-v2"))
    visu_mode = 2;
  init_struct_antFarm(&af);
  parsing(&af, quit_mode);
  // view_parsed(&af);
  // view_graph(&af);
  algo(&af, visu_mode);
  free_antFarm(&af);
  return 0;
}
