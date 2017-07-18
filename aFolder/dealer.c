//--------------------------------------------
// NAME: Velislav Velikov
// CLASS: XI b
// NUMBER: 06
// PROBLEM: #3
//---------------------------------------------

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *Tester(){
	int i=0; //(0-3)
	printf("Buyer 1 takes 1 car.");
	printf("Buyer 1 returns 1 car");
}

void *Dealer(){
	int i=0; //(0-3)
}

int main (int argc, char *argv[])
{
	pthread_t threads[2];
	
	pthread_mutex_init(&mutex, NULL);

	pthread_create(&threads[0], NULL, Tester, NULL);
	pthread_create(&threads[1], NULL, Dealer, NULL);
	
	
 	pthread_join(threads[0],NULL);
	pthread_join(threads[1],NULL);
	
	pthread_mutex_destroy(&mutex);
	return 0;

}

//gcc -Wall -o miners -miners.c -pthread
