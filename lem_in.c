#include "lem_in.h"

int main(int argc, char **argv)
{
  t_antFarm af;
  int quiet_mode;
  int visu_mode;
  int special_algo;

  quiet_mode = 0;
  visu_mode = 0;
  special_algo = 0;
  if (argc > 1 && ft_strcmp(argv[1], "-q"))
    quiet_mode = 1;
  else if (argc > 1 && ft_strcmp(argv[1], "-q2"))
    quiet_mode = 2;
  else if (argc > 1 && ft_strcmp(argv[1], "-v"))
    visu_mode = 1;
  else if (argc > 1 && ft_strcmp(argv[1], "-v2"))
    visu_mode = 2;
  else if (argc > 1 && ft_strcmp(argv[1], "-s"))
    special_algo = 1;
  if (argc > 2 && ft_strcmp(argv[2], "-s"))
    special_algo = 1;
  init_struct_antFarm(&af);
  parsing(&af, quiet_mode);
  if (!special_algo)
    algo2(&af, visu_mode, quiet_mode);
  else
    algo(&af, visu_mode, quiet_mode);
  free_antFarm(&af);
  return 0;
}
