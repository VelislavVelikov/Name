#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h> 

FILE* fp;

int main(int argc, char *argv[])
{	
	int i;
	for(i=1;i<argc;i++){
		printf("Reading file: %s\nNo: %d\n%d total file(s)\n\n",argv[i],i,argc-1);
		fp = fopen(argv[i],"r");
		
		
		fclose(fp);
	}
	
	return 0;
}