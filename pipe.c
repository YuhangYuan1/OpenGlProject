#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
   
   int pid;
   int fd[2];

   pipe(fd);

   pid = fork();
  
   if(pid < 0){
      printf("ERROR! Process create fail!\n");
      exit(0);
   }   

   else if(pid == 0){
 
      close(1);
      dup(fd[1]);
      close(fd[1]);
      close(fd[0]);
      execl("./pre","ls", (char *) 0);
   }

   else{

      wait(NULL);
      close(0);
      dup(fd[0]);
      close(fd[1]);
      close(fd[0]);

      execl("./sort","ls", (char *) 0);

      exit(0);
   }
   
   return 0;
}
