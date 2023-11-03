#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <unistd.h>
#include <sys/wait.h>

char **get_input(char *input);

int main() 
{
    char **command;
    char *input;
    pid_t child_pid;
    int stat_loc;

    while (1) 
    {
        input = readline("unixsh> ");
        command = get_input(input);

        child_pid = fork();
        if (child_pid == 0) {
            /* Child process */
            char *full_path = "/bin/"; // Replace with the full path to your executable
            char *full_command = malloc(strlen(full_path) + strlen(command[0]) + 1);
            strcpy(full_command, full_path);
            strcat(full_command, command[0]);

            char *argv[] = { full_command, NULL };
            char *envp[] = { NULL }; // You can customize the environment if needed

            execve(full_command, argv, envp);

            printf("This won't be printed if execve is successful\n");
            free(full_command); // Free dynamically allocated memory
            exit(1); // Exit the child process if execve fails
        } else {
            waitpid(child_pid, &stat_loc, WUNTRACED);
        }

        free(input);
        free(command);
    }

    return 0;
}