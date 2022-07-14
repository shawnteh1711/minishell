#include <stdlib.h>
#include <crt_externs.h>
#include <string.h>
#include <stdio.h>

int unsetenv(const char *name) 
{ 
	extern char **environ;
    // check if the variable to be removed exists 
    if (getenv(name) == NULL) 
        return -1; 
  
    // calculate the length of the variable 
    int len = strlen(name); 
  
    // take a backup of environment variables 
    char **env = environ; 
    int i = 0; 
    while (*env) 
    { 
        // if the variable to be removed is found 
        // then overwrite it with the next environment 
        // variable and stop searching 
        if (strncmp(*env, name, len) == 0 && (*env)[len] == '=') 
        { 
            // found the environment variable 
            // now shift the remaining variables back by one 
            int j = 0; 
            for (j = i + 1; environ[j]; j++)
			{
				printf("environ[j - 1]: %s\n", environ[j - 1]);
				printf("environ[j]: %s\n", environ[j]);
                environ[j - 1] = environ[j]; 
			}
  
            // the last environment variable will now be NULL 
            // indicating the end of the array 
            environ[j - 1] = NULL; 
            return 0; 
        } 
  
        // move to the next environment variable 
        env++; 
        i++; 
    } 
  
    // the variable was not found in environment 
    // hence we return -1 
    return -1; 
}


int	main(void)
{
	int	i;

	i = unsetenv("USER");
	return (0);
}


// int unsetenv(const char *name)
// {
//     size_t len = strlen(name);
//     if (len == 0 || name[len - 1] == '=')
//         return -1;

//     int i;
//     int found = 0;
//     for (i = 0; environ[i] != NULL; i++) {
//         if (strncmp(name, environ[i], len) == 0 &&
//             (environ[i][len] == '=' || environ[i][len] == '\0')) {
//             // Found it.  Slide everything down one.
//             memmove(&environ[i], &environ[i+1],
//                     sizeof(char *) * (unsigned int)(size - i));
//             found = 1;
//         }
//     }

//     if (found) {
//         // We found it and removed it.  Now we need to
//         // null-terminate the array.  We don't need to worry about
//         // realloc'ing the array because we guaranteed that there's
//         // always extra space at the end.
//         environ[size - 1] = NULL;
//         size--;
//     }

//     return found ? 0 : -1;
// }