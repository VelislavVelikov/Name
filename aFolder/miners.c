//--------------------------------------------
// NAME: Velislav Velikov
// CLASS: XI b
// NUMBER: 06
// PROBLEM: #3
//---------------------------------------------

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int Minerals=0;


pthread_mutex_t mutex;

Moving
while(block(m) == 0){
	sleep(3);
	m++;
	printf("SCV %d is transporting minerals\n", i);
	sleep(2);
	my_minerals+=SCV_Minerals;
	SCV_Minerals=0;
	printf("SCV %d delivered minerals to the Command center\n", i);
}

Command_Center{
	int marine=0
	if(my_minerals>=50){
		if(marine<20){
			my_minerals-=50;
			marine++;
			sleep(1);
			printf("You wanna piece of me, boy?");
		}
	}
}



void *SCV(){
	int i;
	for(i = 1;i<6;i++){
		pthread_mutex_lock(&mutex);
		printf("SCV %d is mining from mineral block %d\n", i, m);
		SCV_Minerals += 8;
		pthread_mutex_unlock(&mutex);
		sleep(2);	
	}
}



int main (int argc, char *argv[])
{
	
	char command;
	//m==marine, s == SCV(4sec); 
	scanf("&c", command);


pthread_t threads[2];
	
	pthread_mutex_init(&mutex, NULL);

	pthread_create(&threads[0], NULL, Gathering, NULL);
	pthread_create(&threads[1], NULL, Selling, NULL);
	
	
 	pthread_join(threads[0],NULL);
	pthread_join(threads[1],NULL);
	
	pthread_mutex_destroy(&mutex);
	printf("Gold: %d\n",Currency);
	return 0;

}

//gcc -Wall -o miners -miners.c -pthread
