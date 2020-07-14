#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
   
   int ch;
   char buffer[50];

   FILE *f = fopen("student_gpa.txt", "w");

   /*Input instructions and input data
   printf("********************************************************\n");
   printf("NOTE: Please input student info by the following format:\n");
   printf("student name + space + gpa(3 digits)\n");
   printf("student name + space + gpa(3 digits)\n");
   printf("...\n");

   printf("\n");
   printf("Input of students' name and gpa:\n");
   printf("\n");*/

   //Read all student name and gpa into the txt file
   ch = getchar();
   while(ch != EOF){
      putc(ch, f);
      ch = getchar();
   }

   fclose(f);

   //Output data
   //printf("\n");
   //printf("\n");
   //printf("Output students whose gpa is above 3.0:\n");
   //printf("\n");


   //Parse the txt file
   f = fopen("student_gpa.txt", "r");
   
   while(fgets(buffer, 50 ,f) != NULL){
      
      //Parse the buffer string
      for(int i = 0; i < strlen(buffer); i++){        
	 if(buffer[i] == ' ' && (int)(buffer[i + 1]) >= 51){		    
	    for(int j = 0; j < i; j++)
	       putchar(buffer[j]);

            printf("\n");
	    break;
	 }
      }
   }
   
   //printf("********************************************************\n");
   fclose(f);
   
   return 0; 
}
