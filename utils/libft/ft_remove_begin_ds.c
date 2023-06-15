#include "libft.h"

char **remove_begin_ds(char **ds)
{
  char **new;
  int i;

  i = 1;
  if (ds == NULL) {
    return 0;
  } else {
    if (!(new = malloc(sizeof(char *) * ft_len_ds(ds))))
      return 0;
    while (ds[i])
    {
      if (!(new[i - 1] = ft_strdup(ds[i])))
        return 0;
      i++;
    }
    new[i - 1] = 0;
  }
  free_ds(ds);
  return new;
}
