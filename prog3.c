#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){
   
   int pid;
   int Pid;
   int PPid;
   int fd[2];
   char *command;

   pid = fork();
  
   if(pid < 0){
      printf("ERROR! Process create fail!\n");
      exit(0);
   }   

   else if(pid == 0){
      
      printf("This is the Child process!\n");
      Pid = getpid();
      printf("the pid of the child process: %d \n \n", Pid);

      for(int i = 1; i < argc; i++){
         command = argv[i];
	 system(command);
      }
   }

   else{
      printf("This is the Parent process!\n");
      PPid = getppid();
      printf("the pid of the parent process: %d \n", PPid);
      printf("\n");

      wait(NULL);
      
      printf("\nBack to the Parent process!\n");
      PPid = getppid();
      printf("the pid of the parent process: %d \n", PPid);
      printf("\n");

      exit(0);
   }
   
   return 0;
}
