#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int lsh_execute(char **args) 
{
  pid_t pid;
  int status;

  pid = fork();
  if (pid == 0) 
  {
    // Child process
    if (execve(args[0], args, NULL) == -1) 
    {
      perror("lsh");
      exit(EXIT_FAILURE);
    }
  } 
  else if (pid < 0) 
  {
    // Error forking
    perror("lsh");
  } 
  else 
  {
    // Parent process
    int child_status;
    while (1) 
    {
      pid_t wpid = wait(&child_status); // Wait for any child to change status

      if (wpid == -1) 
      {
        perror("lsh");
        exit(EXIT_FAILURE);
      }

      if (WIFEXITED(child_status) || WIFSIGNALED(child_status)) 
      {
        break; // Child process has terminated or been signaled
      }
    }
  }
  return 1;
}