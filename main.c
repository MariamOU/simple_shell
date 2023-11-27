#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 100

/**
 * getCommand - Displays a prompt and waits for the user to type a command.
 *
 * @command: The string to store the user's command
 * Return: 1 if a command was entered successfully, 0 if the end of file was reached.
 */
int getCommand(char* command)
{

printf("$ ");

if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
{
return (0);

}

command[strcspn(command, "\n")] = '\0';

return (1);
}

/**
 * executeCommand - Executes a command entered by the user
 *
 * @command: The command
 */
void executeCommand(const char* command)
{
if (strcmp(command, "end of file") == 0)
{
printf("Exiting...\n");
exit(EXIT_SUCCESS);
}
if (access(command, X_OK) == 0)
{
system(command);

}
else
{
printf("Command not found: %s\n", command);
}
}

/**
 * main - the main function
 *
 * @ac: the counter of arguments
 * @av: the arguments
 *Return: 0
 */
int main(int ac, char **av)
{
char command[MAX_COMMAND_LENGTH];
int result;
(void)ac;
(void)av;


while (1)
{
result = getCommand(command);

if (result == 0)
{
printf("End of file reached\n");
break;
}

executeCommand(command);
}

return (0);
}
