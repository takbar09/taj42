#include<stdio.h>
#include<stdlib.h>

void lsh_loop(void) 
{
  char *line;
  char **args;
  int status;

  while (1) 
  {
    printf("> ");
    line = lsh_read_line();
    args = lsh_split_line(line);
    status = lsh_execute(args);

    free(line);
    free(args);

    if (status == 0) 
    {
      break; // Exit the loop when status is 0
    }
  }
}