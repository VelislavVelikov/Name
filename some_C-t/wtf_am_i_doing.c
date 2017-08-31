#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h> 

int main (int argc, char **argv){
   
   FILE *fp;
   char c;
  
   fp = fopen(argv[i],"r");
   while(1){

      c = fgetc(fp);
      
      if( feof(fp) ){
         printf("\n"); 
         break ;
      }
      // if(c != '\n')
         printf("%c", c);
   }
   fclose(fp);
   
   return(0);
}



   // FILE *fp;
   // char c;
  
   // fp = fopen(argv[i],"r");
   // while(1){

   //    c = fgetc(fp);
      
   //    if( feof(fp) ){
   //       printf("\n"); 
   //       break ;
   //    }
   //    // if(c != '\n')
   //       printf("%c", c);
   // }
   // fclose(fp);