Instructions:

This folder contains 6 files:
make
pipe.c 
pre.c 
prog3.c 
sort.c
readme.txt

Please do following steps to run and test programs in this folder.

1. run "./make" on the linux command line to compile pre.c, sort.c, pipe.c, and prog3.c

2. for the problem 1-a, run "./pre", and Input:
   
   Susan 3.1
   John 2.0
   David 3.5
   Jessica 3.4
   EOF
 
   Then the program returns the name of student whose gpa is above 3.0


   for the probelm 1-b, run "./sort", and Input:
   
   Susan
   David
   Jessica
   EOF

   Then the program returns the name of student in the alphabetic order

3. for the problem 2, run "./pipe", and Input:
   
   Susan 3.1
   John 2.0
   David 3.5
   Jessica 3.4
   EOF
 
   Then the program returns the name of student whose gpa is above 3.0 in alphabetic order

4. for the problem 3, run "./prog3" or "./prog3 ls". The program will create a new child process to run the "ls" command. Each process will return its pid, and specify itself. NOTE: the argument can be anything like "ls", "ps".... 

