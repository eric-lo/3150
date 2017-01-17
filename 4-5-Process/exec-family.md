# `exec()` Family

As introduced earlier, `exec()` has several family members. They are summarized as follows. (By courtesy of Dr. Mole Wong)

![](/assets/Screen Shot 2016-09-11 at 11.47.30 PM.png)

The photo above explains the usage of each member. Different `exec()` functions accepts different arguments. For explanation, please refer to the figure below.

![](/assets/Screen Shot 2016-09-12 at 3.19.13 AM.png)

---

```c
/* execlp.c */

#include <stdio.h>
#include <unistd.h>

int main(int argc,char *argv[]){
 printf("Using *execlp* exec ls -l...\n");
 execlp("ls","ls","-l",NULL);
 printf("Program Terminated\n");
 return 0;
}

```
---
```c
/* execle.c */
#include <stdio.h>
#include <unistd.h>


int main(int argc,char *argv[])
{
 char *env[] = {"LS_COLORS=fi=04;33;44",NULL};

 printf("Using *execle* to exec ls -l\n");
 execle("/bin/ls","ls","-l","--color",NULL,env);
 printf("Program Terminated\n");
}

```
---
```c
/* execlv.c */
#include <stdio.h>
#include <unistd.h>


int main(int argc,char *argv[])
{
 char *arg[] = {"ls","-l",NULL};
 printf("Using *execv* to exec ls -l...\n");
 execv("/bin/ls",arg);
 printf("Program Terminated\n");
 return 0;
}

```
---
```c
/* execvp.c */
#include <stdio.h>
#include <unistd.h>


int main(int argc,char *argv[])
{
 char *arg[] = {"ls","-l",NULL};
 printf("Using *execvp* to exec ls -l ...\n");
 execvp("ls",arg);
 printf("Program Terminated\n");
 return 0;
}

---

```c
/* execve.c */
#include <stdio.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
 char *env[] = {"LS_COLORS=fi=04;33;44",NULL};
 char *arg[] = {"ls","-l","--color",NULL};
 printf("Using *execve* to exec ls -l\n");
 execve("/bin/ls",arg,env);
 printf("Program Terminated\n");
}

```




