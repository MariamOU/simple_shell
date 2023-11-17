#include "shell.h"
/**
 * main - The main function
 * @ac: the counter of arguments
 * @av: the arguments
 * Description: program uses the main function
 * Return: 0;
 */

int main(int ac, char **av)
{
char *line;
size_t line_length = 0;
ssize_t num_characters = 0;
(void)ac;
(void)av;

line = NULL;
write(STDOUT_FILENO, "$ ", 2);
num_characters = getline(&line, &line_length, stdin);
if (num_characters == EOF)
{
perror("getline error");
exit(EXIT_FAILURE);
}
printf("%s ", line);

return (0);
}
