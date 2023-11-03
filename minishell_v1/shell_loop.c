#include <stdio.h>

void shell_loop(void)
{
  char *line;
  char **args;
  int status = 1; // Set status to a non-zero value to enter the loop

  while (status) {
    printf("> ");
    // line = read_line();
    // args = split_line(line);
    // status = execute_sh(args);

    // free(line);
    // free(args);
  }
}