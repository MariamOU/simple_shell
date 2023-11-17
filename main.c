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
(void)ac;
(voi)av;
char *line = NULL;
size_t line_length = 0;
ssize_t num_characters = 0;
int i = 0;

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
