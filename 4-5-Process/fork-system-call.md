#`fork` system call

Let's try the following code to see the effect of `fork` !
```c
/* LetsFork/fork1.c */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc,char *argv[])
{
 printf("Before Fork, My PID: [%d]\n",getpid());
 fork();
 printf("After Fork, My PID: [%d]\n",getpid());
 return 0;
}

```
Here is the sample output:
![](/assets/forkc1.png)

You will discover you have two lines of output! This can be explained by the behaviour of `fork`. In the example, Process [8265] is the original process, and process [8266] is a newly spawned process (we call it **child process**).

## Behaviour of `fork`
1. The child process will be spawned after `fork`.
2. The child will continue executing the code after `fork()` is returned, **not** from the beginning.
3. The parent is **still** continue executing the same program.

Then How can we distinguish the parent and child process?

