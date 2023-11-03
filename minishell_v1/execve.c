#include <unistd.h>
#include <stdio.h>

int main() {
    char *binary = "/bin/ls"; // Full path to the 'ls' binary
    char *argv[] = { "ls", "-l", "-h", "-a", NULL };
    char *envp[] = { NULL }; // You can customize the environment if needed

    execve(binary, argv, envp);

    // If execve fails, it will not reach this point.
    perror("execve"); // Print an error message if execve fails.

    return 1; // Indicate failure
}