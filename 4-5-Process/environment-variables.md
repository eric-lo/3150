# Environment Variable

In the shell the environment variables are a set of strings that stores the settings, for example, `PATH` variable stores the path searching setting and `http_proxy` sets the proxy server setting.

There are many ways to get environment variables. One of the ways is from the argument of `main` function.

```c
#include <stdio.h>
int main(int argc,char *argv[], char* envp[])
{ 
    int i; 
    for (i = 0; envp[i];i++) 
    { 
        printf("[%d]: %s\n",i,envp[i]);
    } 
    return 0;
}
```
Take a note of the `main` function parameter. There is an extra item of `char * envp[]`. This allows the program to retrieve the system environment variable.