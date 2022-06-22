#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_NUM_ARGUMENTS 10

int main()
{
    char command_line[MAX_COMMAND_LENGTH];
    char *arguments[MAX_NUM_ARGUMENTS];

    while (1)
    {
        printf("$ ");
        fgets(command_line, sizeof(command_line), stdin);
        command_line[strlen(command_line) - 1] = '\0';

        char *token = strtok(command_line, " ");
        int index = 0;
        while (token != NULL)
        {
            arguments[index] = token;
            index++;
            token = strtok(NULL, " ");
        }

        if (strcmp(arguments[0], "exit") == 0)
        {
            exit(0);
        }

        int result = execvp(arguments[0], arguments);
        if (result == -1)
        {
            perror("Error");
        }
    }

    return 0;
}