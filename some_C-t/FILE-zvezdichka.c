#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
// FILE *fd;

int main(int argc, char **argv){
	int i,m,result;
	char buffer[1];
	int fd;
	for(i=1; i<argc; i++){
		
		pid_t pid = fork();

		if(pid == 0){
			
			fd = open(argv[i], O_RDONLY);
			printf("==> %s <==\n\n",argv[i]);

			while(result = read(fd, buffer, 1)){
				write(STDOUT_FILENO,buffer,1);
				write(STDOUT_FILENO,buffer,1);
			}
			

			// while(1){
		 	//    buffer = fgetc(fd);			      
			// 	printf("%c", buffer);
			//     printf("%c", buffer);
			// 	if( feof(fd) ){
			//     	printf("\n\nEOF\n"); 
			//     	break ;
			//     }
			// }
			printf("\n\n\n");
			
			close(fd);

			return 1;	
		}
		else if(pid <0){			
			perror("Problem creating child process!");
			return -1;
		}
		// wait(NULL);
	}
	
	for(m=0; m<i+1; m++){
		wait(NULL);
	}

	printf("O4EVIDNO MI TR RETURN A NE BREAK! ;)\n");

	return 0;
}