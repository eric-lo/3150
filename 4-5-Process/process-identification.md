# Process Identification

In the system, there are lots of processes. We can identify one process uniquely by its **Process ID** or **PID**.

We have a special system call `getpid()` to retrieve the PID of the current process.

```cpp
/* getpid.c */
#include <stdio.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
    printf("My PID is %d\n",getpid());
}
```

You can run multiple time to check the pid changes!
