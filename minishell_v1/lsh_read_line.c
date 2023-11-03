#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

char *lsh_read_line(void) 
{
  char *line = readline(""); // Use readline to get input

  if (line == NULL) 
  {
    exit(EXIT_SUCCESS); // We received an EOF or an error
  }

  // Add the input to history for command recall
  add_history(line);

  return line;
}