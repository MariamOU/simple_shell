#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"
/**
 * main - The main function
 * @ac: the counter of arguments
 * @av: the arguments
 * Description: program uses the main function
 * Return: 0;
 */
#define COMMAND_LENGTH 100
int main(int ac, char **av)
{
char command[COMMAND_LENGTH];
pid_t pid;
int status;
(void)ac;
(void)av;




while (1)
{
printf("$ ");
if (fgets(command, COMMAND_LENGTH, stdin) == NULL)
{
printf("\n");
break;
}
command[strcspn(command, "\n")] = '\0';
pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execlp(command, command, NULL) == -1)
{
perror("execlp");
exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &status, 0);

if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
{
break;
}
}
}

return (0);
}
