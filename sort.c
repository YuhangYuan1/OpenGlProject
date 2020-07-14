#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure node for the linked list
struct Node{
   char name[20];
   struct Node *next;
};

int main(){

   char ch;
   char buffer[20];
   FILE *f = fopen("student_name.txt", "w");

   struct Node *HeadNode = NULL;
   struct Node *cursor = NULL;
   struct Node *precursor = NULL; 

   /*Input instructions and input data
   printf("********************************************************\n");
   printf("NOTE: Please input student name by the following format:\n");
   printf("student name\n");
   printf("student name\n");
   printf("...\n");
   printf("\n");
   printf("Input of students' name:\n");
   printf("\n");*/ 
   
   //Read all student name into the txt file
   ch = getchar();
   while(ch != EOF){
      putc(ch, f);
      ch = getchar();
   }

   fclose(f);

   //Parse the text file
   f = fopen("student_name.txt", "r");
  
   //Insert node into linked list with the alphabetical order 
   while(fgets(buffer, 20, f) != NULL){
      
      //When the linked list is empty
      if(HeadNode == NULL){
         HeadNode = (struct Node*) malloc(sizeof(struct Node));
	 strcpy(HeadNode->name, buffer);
	 HeadNode->next = NULL;
      }
            
      //when the linked list is NOT empyt
      else{
         cursor = HeadNode;
	 while(cursor != NULL && cursor->name[0] <= buffer[0]){
	   precursor = cursor; 
	   cursor = cursor->next;	 
	 }

         if(precursor == NULL && cursor != NULL){
	    precursor = (struct Node*) malloc(sizeof(struct Node));
	    precursor->next = cursor;
	    HeadNode = precursor;

	    strcpy(precursor->name, buffer);
	 }

	 else if(precursor != NULL && cursor == NULL){
	    cursor = (struct Node*) malloc(sizeof(struct Node));
	    precursor->next = cursor;
	    cursor->next = NULL;

	    strcpy(cursor->name, buffer);
	 }

         else{
	    precursor->next = (struct Node*) malloc(sizeof(struct Node));
	    precursor = precursor->next;
	    precursor->next = cursor;

	    strcpy(precursor->name, buffer);
	 }	 
      }
      
      precursor = NULL;
      cursor = NULL;      
   }

   fclose(f);

   //Print the linked list
   //printf("\n");
   //printf("\n");
   //printf("This is the student name output by the alphabetic order:\n");
   //printf("\n");
   cursor = HeadNode;
   while(cursor != NULL){
      printf("%s", cursor->name);
      cursor = cursor->next;
   }

   //printf("********************************************************\n");

   //Free up the memory
   cursor = HeadNode;
   while(cursor != NULL){
      HeadNode = cursor->next;
      free(cursor);
      cursor = HeadNode;
   }

   return 0;
}
