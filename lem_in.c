#include "lem_in.h"

int main(int argc, char **argv)
{
  t_antFarm af;
  int quiet_mode;
  int visu_mode;

  quiet_mode = 0;
  visu_mode = 0;
  if (argc > 1 && ft_strcmp(argv[1], "-q"))
    quiet_mode = 1;
  else if (argc > 1 && ft_strcmp(argv[1], "-q2"))
    quiet_mode = 2;
  else if (argc > 1 && ft_strcmp(argv[1], "-v"))
    visu_mode = 1;
  else if (argc > 1 && ft_strcmp(argv[1], "-v2"))
    visu_mode = 2;
  init_struct_antFarm(&af);
  parsing(&af, quiet_mode);
  algo2(&af, visu_mode, quiet_mode);
  free_antFarm(&af);
  return 0;
}
