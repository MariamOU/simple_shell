#ifndef SHELL_H
#define SHELL_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
int getCommand(char* command);
void executeCommand(const char* command);
#endif /* SHELL_H */
